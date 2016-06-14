public class MovementComponent : Component {

    public MovementComponent () {

    }

    public void handle_events() {

        PositionComponent pos = entity.get_component<PositionComponent>();
        AnimationComponent ani = entity.get_component<AnimationComponent>();
        var keyboardstate = SDL.Input.Keyboard.get_state ();
        if( keyboardstate[SDL.Input.Scancode.LEFT] == 1 ){
            if( ani != null )
                ani.current_animation = "running";
            if( pos.x >= 0 )
                pos.next_x = pos.x - 1;
            pos.flip = SDL.Video.RendererFlip.HORIZONTAL;
        } else if( keyboardstate[SDL.Input.Scancode.RIGHT] == 1 ){
            if( ani != null )
                ani.current_animation = "running";
            pos.next_x = pos.x + 1;
            pos.flip = SDL.Video.RendererFlip.NONE;
        } else {
            if( ani != null )
                ani.current_animation = "still";
        }
    }

}
