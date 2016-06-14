// TODO: Find a way to get efficient entities with specific components
//       in an efficient way. Systems always need the same entities

namespace Engine {
    public class Engine {
        private SystemManager systemManager = new SystemManager();
        private EntityManager entityManager = new EntityManager();

        public void addSystem(EntitySystem system) {
            systemManager.addSystem(system);
            system.addedToEngine(this);
        }

        public void removeSystem(EntitySystem system) {
            systemManager.removeSystem(system);
            system.removedFromEngine(this);
        }

        public void update() {
            Gee.List<EntitySystem> systems = systemManager.getSystems();
            foreach(EntitySystem system in systems) {
                system.update(0f);
            }
        }

        public Gee.List<Entity> getEntitiesFor(Gee.List<Type> componenttypes) {
            return entityManager.getEntitiesFor(componenttypes);
        }

        public Entity createEntity() {
            var e = new Entity();
            entityManager.addEntity(e);
            return e;
        }
    }
}
