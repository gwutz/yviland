using Tiled;

const int FRAMES_PER_SECOND = 30;
const int FRAMEDURATION = 1000 / FRAMES_PER_SECOND;

public static void main(string[] argv) {

    SDL.init (SDL.InitFlag.EVERYTHING);
    SDLTTF.init();
    var game = new Game (640, 512);

    while( game.is_running ()){
        var start = SDL.Timer.get_ticks ();

        game.handle_events ();
        game.update ();

        var end = SDL.Timer.get_ticks ();
        var duration = end - start;
        if( duration < FRAMEDURATION ){
            SDL.Timer.delay (FRAMEDURATION - duration);
        }
    }

    game.quit ();
}
