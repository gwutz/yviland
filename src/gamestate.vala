using SDL.Video;
using Tiled;

public abstract class GameState {
    protected Engine.Engine engine = new Engine.Engine();
    protected Camera ncamera;

    private Gee.List<GameState> states {
        get; set; default = new Gee.ArrayList<GameState>();
    }

    public GameState (string map_filename, TextureManager t, Renderer r) {
        Rect camerarect;
        r.get_viewport (out camerarect);

        this.ncamera = new Camera(0, 0);

        add_entities();
        add_map(map_filename);
        add_systems(t, r);
    }

    public void add_map(string map_filename) {
        var entity = this.engine.createEntity();
        entity.add_component(new TilemapComponent2(loadMap(map_filename)));
        create_map(entity);
    }

    public abstract void create_map(Engine.Entity map);

    public virtual void add_entities() {

    }

    public virtual void add_systems(TextureManager t, Renderer r) {
        this.engine.addSystem(new TextureSystem(r, t));
        this.engine.addSystem(new MovementSystem());
        this.engine.addSystem(new AnimationSystem());
        this.engine.addSystem(new CollisionSystem());
        this.engine.addSystem(new TilemapRenderSystem(ncamera, r, t));
        this.engine.addSystem(new RenderSystem(ncamera, r, t));
    }

    public virtual void update() {
        this.engine.update();
    }
}
