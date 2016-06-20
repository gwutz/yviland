namespace Engine {
    public class SystemManager {

        private Gee.List<System> systems = new Gee.ArrayList<System>();
        private Gee.Map<Type, System> systemsByType = new Gee.HashMap<Type, System>();

        public SystemManager() {

        }

        public void addSystem(System system) {
            Type t = system.get_type();
            System oldSystem = getSystem(t);
            if(oldSystem != null) {
                removeSystem(oldSystem);
            }
            systems.add(system);
            systemsByType.set(t, system);
        }

        public void removeSystem(System system) {
            systems.remove(system);
            systemsByType.unset(system.get_type());
        }

        public System getSystem(Type t) {
            return systemsByType.get(t);
        }

        public Gee.List<System> getSystems() {
            return systems;
        }
    }
}
