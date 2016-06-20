// TODO: Find a way to get efficient entities with specific components
//       in an efficient way. Systems always need the same entities

namespace Engine {

    namespace Color {
        public const SDL.Video.Color BLACK = {0, 0, 0, 255};
    }

    public enum State {
        PAUSED,
        RUNNING
    }

    public class Engine {
        private SystemManager systemManager = new SystemManager();
        private EntityManager entityManager = new EntityManager();
        public State state = State.RUNNING;
        private bool update_entities = false;

        public void addSystem(System system) {
            systemManager.addSystem(system);
            system.addedToEngine(this);
        }

        public void removeSystem(System system) {
            systemManager.removeSystem(system);
            system.removedFromEngine(this);
        }

        public void update() {
            Gee.List<System> systems = systemManager.getSystems();
            foreach(System system in systems) {
                if(system.get_type().is_a(typeof(EntitySystem)) &&
                        update_entities) {
                    var s = system as EntitySystem;
                    s.updateEntities();
                }
            }
            if(update_entities) update_entities = false;
            foreach(System system in systems) {
                system.update(0f);
            }
        }

        public Gee.List<Entity> getEntitiesFor(Gee.List<Type> componenttypes) {
            return entityManager.getEntitiesFor(componenttypes);
        }

        public Entity createEntity() {
            var e = new Entity();
            entityManager.addEntity(e);
            update_entities = true;
            return e;
        }

        public void removeEntity(Entity e) {
            entityManager.removeEntity(e);

            Gee.List<System> systems = systemManager.getSystems();
            foreach(System system in systems) {
                if(system.get_type().is_a(typeof(EntitySystem))) {
                    var s = system as EntitySystem;
                    s.updateEntities();
                }
            }
        }
    }
}
