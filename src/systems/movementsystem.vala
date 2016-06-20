// modules: sdl2 engine gee-0.8
// vapidirs: ../../engine
public class MovementSystem : Engine.EntitySystem {
    private weak Camera camera;

    public MovementSystem(Camera camera) {
        this.camera = camera;
    }

    public override Type[] getEntityTypes() {
        return {
            typeof(MovementComponent),
            typeof(PositionComponent)
        };
    }

    public override void update(float deltaTime) {
        var keyboardstate = SDL.Input.Keyboard.get_state ();

        if(engine.state != Engine.State.PAUSED) {
            foreach (Engine.Entity e in entities) {
                PositionComponent pos = e.get_component<PositionComponent>();
                AnimationComponent ani = e.get_component<AnimationComponent>();
                RenderComponent rend = e.get_component<RenderComponent>();

                debug("camerawidth %u pos.x %d", camera.w, pos.x);
                //stdout.printf("position %d\n", pos.x);
                if( keyboardstate[SDL.Input.Scancode.LEFT] == 1 ){
                    if( ani != null )
                        ani.current_animation = "running";
                    if( pos.x >= 0 ) {
                        if(pos.x + rend.w/2 - camera.x < camera.w/2 && camera.x != 0) {
                            camera.x -= 2; 
                        } else {
                            pos.velocity_x = -2;
                        }
                    }
                    pos.flip = SDL.Video.RendererFlip.HORIZONTAL;
                } else if( keyboardstate[SDL.Input.Scancode.RIGHT] == 1 ){
                    if( ani != null )
                        ani.current_animation = "running";
                    if(pos.x.abs() + rend.w/2 - camera.x > camera.w/2) {
                        camera.x += 2;
                    } else {
                        pos.velocity_x = 2;
                    }
                    pos.flip = SDL.Video.RendererFlip.NONE;
                } else {
                    pos.velocity_x = 0;
                    if( ani != null )
                        ani.current_animation = "still";
                }

                if(keyboardstate[SDL.Input.Scancode.UP] == 1 && pos.state != PositionComponent.EntityState.AIR ) {
                    pos.velocity_y -= 9;
                    pos.state = PositionComponent.EntityState.AIR;
                    var ent = engine.createEntity();
                    ent.add_component(new RenderComponent("fxjump",
                                "data/fxjump.png", 18, 6));
                    ent.add_component(new PositionComponent(pos.x+6, pos.y +
                                (int)rend.h-6));
                    var anic = new AnimationComponent();
                    anic.add_animation(new Animation("jump", 0, 6, 1, false,
                                true));
                    ent.add_component(anic);
                }
            }
        }
    }
}
