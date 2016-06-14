using SDL.Video;
using Tiled;

public abstract class GameState {
    private Tiled.Map map { get; set; }
    protected Gee.Map<string, Entity> objects { get; set; default = new Gee.HashMap<string, Entity>(); }
    private Gee.List<GameState> states {
        get; set; default = new Gee.ArrayList<GameState>();
    }
    protected Rect camera;

    public GameState (string map_filename, TextureManager t, Renderer r) {
        Rect camerarect;
        r.get_viewport (out camerarect);

        var e = new Entity ("map");
        e.add_component (new TilemapComponent (loadMap (map_filename), t, r));
        e.add_component (new CollisionComponent(0,0,0,0));

        objects.set (e.name, e);

        e = new Entity("camera");
        e.add_component(new CameraComponent(camerarect.w, camerarect.h));
        e.add_component(new PositionComponent(0, 0));

        objects.set (e.name, e);
    }

    public virtual void handle_events() {
        foreach( GameState state in states ){
            state.handle_events ();
        }
        foreach( Entity e in this.objects.values ){
            var component = e.get_component<MovementComponent>();
            if( component != null ){
                component.handle_events ();
            }
        }
    }

    public virtual void update() {
        foreach(Entity e in this.objects.values) {
            var component = e.get_components<UpdateComponent>();
            if(component != null)
                component.update();
        }
    }

    public virtual void draw(TextureManager t, Renderer r) {

        this.objects.get ("map").get_component<TilemapComponent>().render (objects.get("camera"));

        foreach( Entity e in this.objects.values ){
            var component = e.get_component<RenderComponent>();
            if( component != null ){
                component.render (t, r);
            }
        }
    }

}
