using SDL.Video;
using Tiled;

public abstract class GameState {
    protected Engine.Engine engine = new Engine.Engine();
    protected Camera ncamera;

    private Gee.List<GameState> states {
        get; set; default = new Gee.ArrayList<GameState>();
    }

    public GameState (string map_filename, TextureManager t, FontManager f, Renderer r) {
        Rect camerarect;
        r.get_viewport (out camerarect);

        this.ncamera = new Camera(0, 0, camerarect.w/4, camerarect.h/4);

        add_entities();
        add_map(map_filename);
        add_systems(t, f, r);
    }

    public void add_map(string map_filename) {
        var entity = this.engine.createEntity();
        entity.add_component(new TilemapComponent2(loadMap(map_filename)));
        create_map(entity);
    }

    public abstract void create_map(Engine.Entity map);

    public virtual void add_entities() {
        var entity = this.engine.createEntity();
        entity.add_component(new
                ResourceComponent("defaultfont", "data/default.ttf", 12, ResourceComponent.ResourceType.FONT));
    }

    public virtual void add_systems(TextureManager t, FontManager f, Renderer r) {
        this.engine.addSystem(new ResourceLoaderSystem(f));
        this.engine.addSystem(new TextureSystem(r, t));
        this.engine.addSystem(new MovementSystem(ncamera));
        this.engine.addSystem(new AnimationSystem());
        this.engine.addSystem(new CollisionSystem());
        this.engine.addSystem(new RenderSystem(ncamera, r, t));
        this.engine.addSystem(new TilemapRenderSystem(ncamera, r, t));
        this.engine.addSystem(new TextRenderSystem(f, r));
    }

    public virtual void update() {
        this.engine.update();
    }

    public void togglePause() {
        if(engine.state == Engine.State.PAUSED) {
            engine.state = Engine.State.RUNNING;
        } else if (engine.state == Engine.State.RUNNING) {
            engine.state = Engine.State.PAUSED;
        }
    }
}
