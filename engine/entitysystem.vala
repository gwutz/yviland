namespace Engine {
    public abstract class EntitySystem : Object {
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
}
