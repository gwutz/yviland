using Tiled;

const int FRAMES_PER_SECOND = 60;
const int FRAMEDURATION = 1000 / FRAMES_PER_SECOND;

public static void main(string[] argv) {

    SDL.init (SDL.InitFlag.EVERYTHING);
    var game = new Game (640, 480);

    while( game.is_running ()){
        var start = SDL.Timer.get_ticks ();

        game.handle_events ();
        game.update ();
        game.draw ();

        var end = SDL.Timer.get_ticks ();
        var duration = end - start;
        if( duration < FRAMEDURATION ){
            SDL.Timer.delay (FRAMEDURATION - duration);
        }
    }

    game.quit ();
}
