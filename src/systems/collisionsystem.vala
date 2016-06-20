// modules: sdl2 engine gee-0.8
// vapidirs: ../../engine
public class CollisionSystem : Engine.EntitySystem {
    private Engine.Entity mapentity;

    public override void addedToEngine(Engine.Engine engine) {
        base.addedToEngine(engine);
        this.mapentity = engine.getEntitiesFor(new Gee.ArrayList<Type>.wrap(
            { typeof(TilemapComponent2) }
        ))[0];
    }

    public override Type[] getEntityTypes() {
        return {
            typeof(CollisionComponent),
            typeof(PositionComponent)
        };
    }

    public override void update(float deltaTime) {
        if(engine.state != Engine.State.PAUSED) {
            foreach (Engine.Entity e in entities) {
                PositionComponent pos = e.get_component<PositionComponent>();
                CollisionComponent collision = e.get_component<CollisionComponent>();
                var move = e.get_component<MovementComponent>();
                if(move != null) {
                    if(pos.velocity_y < 4) {
                        pos.velocity_y += 1;
                    }
                }

                // test against map
                var mapcomponent = mapentity.get_component<TilemapComponent2>();
                if(mapcomponent.map.collidesHorizontal(collision.getHAbsoluteBox())) {
                    pos.velocity_x = 0;
                }
                if(mapcomponent.map.collidesWith(collision.getAbsoluteBox())) {
                    //stdout.printf("collision\n");
                    pos.velocity_y = 0;
                    pos.state = PositionComponent.EntityState.GROUND;
                }

                // test against entities
                foreach (Engine.Entity e2 in entities) {
                    if(e2 != e) {
                        var collision2 = e2.get_component<CollisionComponent>();
                        var textc = e2.get_component<TextComponent>();
                        var ani = e2.get_component<AnimationComponent>();
                        if(collision.getHAbsoluteBox().is_intersecting(collision2.getHAbsoluteBox())) {
                            pos.velocity_x = 0;
                        }
                        if(collision.getAbsoluteBox().is_intersecting(collision2.getAbsoluteBox())) {
                            pos.velocity_y = 0;
                            pos.state = PositionComponent.EntityState.GROUND;
                            if(textc != null) {
                                textc.visible = true;
                                textc.timer = 60;
                                if(ani != null) ani.current_animation =
                                    "touched";
                            }
                        } else {
                            if(textc != null) {
                                textc.timer -= 1;
                                if(textc.timer == 0) {
                                    textc.visible = false;
                                }
                            }
                        }

                    }
                }


            }
        }
    }
}
