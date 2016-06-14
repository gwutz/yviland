public class PositionComponent : Component {
    public int x;
    public int y;
    public int next_x;
    public int next_y;
    public int center {
        get {
            var ani = this.entity.get_component<AnimationComponent>();
            return (ani.sprite_width + 1) / 2 + x;
        }
    }
    public SDL.Video.RendererFlip flip = SDL.Video.RendererFlip.NONE;

    public PositionComponent (int x, int y) {
        this.x = x;
        this.y = y;
        this.next_x = x;
        this.next_y = y;
    }

    public void update_position() {
        x = next_x;
        y = next_y;
    }

    public void reset_position() {
        next_x = x;
        next_y = y;
    }

}
