public class PositionComponent : Engine.Component {
    public int x;
    public int y;
    public int velocity_x = 0;
    public int velocity_y = 0;

    public EntityState state = EntityState.AIR;

    public enum EntityState {
        GROUND,
        AIR
    }

    public SDL.Video.RendererFlip flip = SDL.Video.RendererFlip.NONE;

    public PositionComponent (int x, int y) {
        this.x = x;
        this.y = y;
    }

    public void update_position() {
        x += velocity_x;
        y += velocity_y;
    }

}
