
public class AnimationSystem : Engine.EntitySystem {
    public override Type[] getEntityTypes() {
        return {
            typeof(AnimationComponent)
        };
    }

    public override void update(float deltaTime) {
        foreach(Engine.Entity e in entities) {
            var ani = e.get_component<AnimationComponent>();
            if(ani.next_animation()) {
                engine.removeEntity(e);
            }
        }
    }
}
