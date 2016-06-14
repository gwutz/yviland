using SDL.Video;
using Tiled;

public abstract class GameState {
    protected Engine.Engine engine;
    protected Camera ncamera;
    private Tiled.Map map { get; set; }
    protected Gee.Map<string, Engine.Entity> objects { get; set; default = new Gee.HashMap<string, Engine.Entity>(); }
    private Gee.List<GameState> states {
        get; set; default = new Gee.ArrayList<GameState>();
    }
    //protected Rect camera;

    public GameState (string map_filename, TextureManager t, Renderer r) {
        Rect camerarect;
        r.get_viewport (out camerarect);

        this.ncamera = new Camera(0, 0);

        this.engine = new Engine.Engine();

        // Entities
        var entity = this.engine.createEntity();
        entity.add_component(new TilemapComponent2(loadMap(map_filename)));

        // Systems
        this.engine.addSystem(new TilemapRenderSystem(ncamera, r, t));
        this.engine.addSystem(new RenderSystem(ncamera, r, t));

    }

    public virtual void handle_events() {
        foreach( GameState state in states ){
            state.handle_events ();
        }
        foreach( Engine.Entity e in this.objects.values ){
            var component = e.get_component<MovementComponent>();
            if( component != null ){
                component.handle_events ();
            }
        }
    }

    public virtual void update() {

        foreach(Engine.Entity e in this.objects.values) {
            var component = e.get_components<Engine.UpdateComponent>();
            if(component != null)
                component.update();
        }
        this.engine.update();
    }

    /*public virtual void draw(TextureManager t, Renderer r) {

        //this.objects.get ("map").get_component<TilemapComponent>().render (objects.get("camera"));

        foreach( Entity e in this.objects.values ){
            var component = e.get_component<RenderComponent>();
            if( component != null ){
                component.render (t, r);
            }
        }
    }*/

}
