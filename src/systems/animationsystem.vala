
public class AnimationSystem : Engine.EntitySystem {
    private Gee.List<Engine.Entity> entities;

    public override void addedToEngine(Engine.Engine engine) {
        base.addedToEngine(engine);
        this.entities = engine.getEntitiesFor(new Gee.ArrayList<Type>.wrap(
            { typeof(AnimationComponent) }
        ));
    }

    public override void update(float deltaTime) {
        foreach(Engine.Entity e in entities) {
            var ani = e.get_component<AnimationComponent>();
            ani.next_animation();
        }
    }
}
