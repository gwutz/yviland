public class EntityManager {
    Gee.List<Entity> entities = new Gee.ArrayList<Entity>();

    public void addEntity(Entity entity) {
        entities.add(entity);
    }

    public void removeEntity(Entity entity) {
        entities.remove(entity);
    }

    public Gee.List<Entity> getEntities() {
        return entities;
    }

    public Gee.List<Entity> getEntitiesFor(Gee.List<Type> componenttypes) {
        Gee.List<Entity> family = new Gee.ArrayList<Entity>();
        foreach(Entity e in entities) {
            foreach(Type t in componenttypes) {
                if(e.has_component(t)) {
                    family.add(e);
                }
            }
        }

        return family;
    }
}
