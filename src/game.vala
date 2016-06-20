// modules: sdl2 engine gee-0.8 tiled
// vapidirs: ../engine ../tmx
using SDL;
using Gee;
using Tiled;

public class Game : GLib.Object {
    private bool running;
    private Video.Window window;
    private Video.Renderer renderer;
    private TextureManager textureManager;
    private FontManager fontManager;
    private GameState state;

    public Game (int width, int height) {
        this.running = true;

        this.window = new Video.Window ("Yviland", 
                                        Video.Window.POS_CENTERED,
                                        Video.Window.POS_CENTERED,
                                        width,
                                        height,
                                        Video.WindowFlags.RESIZABLE);
        this.renderer = Video.Renderer.create (this.window,
                                               -1,
                                               Video.RendererFlags.ACCELERATED 
                                               | Video.RendererFlags.PRESENTVSYNC);
        //this.renderer.set_scale (4, 4);
        this.textureManager = new TextureManager ();
        this.fontManager = new FontManager();
        this.window.show ();
        this.state = new Testlevel (textureManager, fontManager, renderer);

    }

    public bool is_running() {
        return this.running;
    }

    public void handle_events() {
        Event event;
        while( Event.poll (out event) == 1 ){
            switch( event.type ){
            case EventType.QUIT:
                this.running = false;
                break;
            case EventType.KEYDOWN:
                if(event.key.keysym.scancode == SDL.Input.Scancode.P)
                    state.togglePause();
                break;
            }
        }
    }

    public void update() {
        this.renderer.set_draw_color (60, 128, 200, 255);
        this.renderer.clear ();
        this.state.update ();
        this.renderer.present ();
    }

    public void quit() {
        SDL.quit ();
    }

}
