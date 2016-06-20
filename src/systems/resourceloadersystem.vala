public class ResourceLoaderSystem : Engine.IteratingEntitySystem {
    private weak FontManager fontManager;

    public ResourceLoaderSystem(FontManager fontManager) {
        this.fontManager = fontManager;
    }

    public override Type[] getEntityTypes() {
        return {
            typeof(ResourceComponent)
        };
    }
    
    public override void processEntity(float deltaTime, Engine.Entity e) {
        var resource = e.get_component<ResourceComponent>();
        switch(resource.type) {
            case ResourceComponent.ResourceType.FONT:
                if(!fontManager.loaded(resource.identifier)) {
                    fontManager.load(resource.identifier,
                                     resource.filename,
                                     resource.ptsize);
                }
                break;
        }
    }
}
