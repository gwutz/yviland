
public class MovementSystem : Engine.EntitySystem {
    private Gee.List<Engine.Entity> entities;


    public override void addedToEngine(Engine.Engine engine) {
        base.addedToEngine(engine);
        this.entities = engine.getEntitiesFor(new Gee.ArrayList<Type>.wrap(
            { typeof(MovementComponent), typeof(PositionComponent) }
        ));
    }

    public override void update(float deltaTime) {
        foreach (Engine.Entity e in entities) {
            PositionComponent pos = e.get_component<PositionComponent>();
            AnimationComponent ani = e.get_component<AnimationComponent>();
            var keyboardstate = SDL.Input.Keyboard.get_state ();
            if( keyboardstate[SDL.Input.Scancode.LEFT] == 1 ){
                if( ani != null )
                    ani.current_animation = "running";
                if( pos.x >= 0 )
                    pos.velocity_x = -1;
                pos.flip = SDL.Video.RendererFlip.HORIZONTAL;
            } else if( keyboardstate[SDL.Input.Scancode.RIGHT] == 1 ){
                if( ani != null )
                    ani.current_animation = "running";
                pos.velocity_x = 1;
                pos.flip = SDL.Video.RendererFlip.NONE;
            } else {
                pos.velocity_x = 0;
                if( ani != null )
                    ani.current_animation = "still";
            }

            if(keyboardstate[SDL.Input.Scancode.UP] == 1 && pos.state != PositionComponent.EntityState.AIR ) {
                pos.velocity_y -= 9;
                pos.state = PositionComponent.EntityState.AIR;
            }
        }
    }
}
