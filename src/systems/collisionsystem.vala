public class CollisionSystem : Engine.EntitySystem {
    private Gee.List<Engine.Entity> entities;
    private Engine.Entity mapentity;

    public override void addedToEngine(Engine.Engine engine) {
        base.addedToEngine(engine);
        this.entities = engine.getEntitiesFor(new Gee.ArrayList<Type>.wrap(
            { typeof(CollisionComponent), typeof(PositionComponent) }
        ));

        this.mapentity = engine.getEntitiesFor(new Gee.ArrayList<Type>.wrap(
            { typeof(TilemapComponent2) }
        ))[0];
    }

    public override void update(float deltaTime) {
        foreach (Engine.Entity e in entities) {
            PositionComponent pos = e.get_component<PositionComponent>();
            CollisionComponent collision = e.get_component<CollisionComponent>();
            if(pos.velocity_y < 4) {
                pos.velocity_y += 1;
            }

            var mapcomponent = mapentity.get_component<TilemapComponent2>();
            if(mapcomponent.map.collidesHorizontal(collision.getHAbsoluteBox())) {
                pos.velocity_x = 0;
            }
            if(mapcomponent.map.collidesWith(collision.getAbsoluteBox())) {
                //stdout.printf("collision\n");
                pos.velocity_y = 0;
                pos.state = PositionComponent.EntityState.GROUND;
            }



        }
    }
}
