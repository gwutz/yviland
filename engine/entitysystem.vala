namespace Engine {
    public abstract class System : Object {
        public weak Engine engine;

        public virtual void addedToEngine(Engine engine) {
            this.engine = engine;
        }

        public virtual void removedFromEngine(Engine engine) {
            if(engine == this.engine) {
                this.engine = null;
            }
        }

        public abstract void update(float deltaTime);
    }

    public abstract class EntitySystem : System {
        protected Gee.List<Entity> entities;

        public abstract Type[] getEntityTypes();

        public override void addedToEngine(Engine engine) {
            base.addedToEngine(engine);
            updateEntities();
        }

        public virtual void updateEntities() {
            this.entities = engine.getEntitiesFor(new Gee.ArrayList<Type>.wrap(
                        getEntityTypes()));
        }

    }

    public abstract class IteratingEntitySystem : EntitySystem {

        public override void update(float deltaTime) {
            foreach(Entity e in entities) {
                processEntity(deltaTime, e);
            }
        }

        public abstract void processEntity(float deltaTime, Entity e);
    }
}
