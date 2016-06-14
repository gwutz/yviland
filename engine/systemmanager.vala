namespace Engine {
    public class SystemManager {

        private Gee.List<EntitySystem> systems = new Gee.ArrayList<EntitySystem>();
        private Gee.Map<Type, EntitySystem> systemsByType = new Gee.HashMap<Type, EntitySystem>();

        public SystemManager() {

        }

        public void addSystem(EntitySystem system) {
            Type t = system.get_type();
            EntitySystem oldSystem = getSystem(t);
            if(oldSystem != null) {
                removeSystem(oldSystem);
            }
            systems.add(system);
            systemsByType.set(t, system);
        }

        public void removeSystem(EntitySystem system) {
            systems.remove(system);
            systemsByType.unset(system.get_type());
        }

        public EntitySystem getSystem(Type t) {
            return systemsByType.get(t);
        }

        public Gee.List<EntitySystem> getSystems() {
            return systems;
        }
    }
}
