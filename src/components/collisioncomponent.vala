using SDL.Video;

public class CollisionComponent : Component {
    public Rect box { get; set; }
    public collisionFunc collision;

    public delegate void collisionFunc();

    public CollisionComponent (int x, int y, uint w, uint h) {
        this.box = Rect () {
            x = x, y = y, w = w, h = h
        };
    }

    public Rect getAbsoluteBox(PositionComponent camera) {
        var pos = this.entity.get_component<PositionComponent>();

        return Rect() {
            x = pos.next_x + box.x + camera.x - 1,
            y = pos.next_y + box.y,
            w = box.w,
            h = box.h
        };
    }

    public bool collidesWith(CollisionComponent other, Entity camera) {
        var mapcomponent = this.entity.get_component<TilemapComponent>();
        if( mapcomponent != null ){
            // i am the map

            if (mapcomponent.map.collidesWith(other.getAbsoluteBox(camera.get_component<PositionComponent>()))) {
                return true;
            }
        }
        mapcomponent = other.entity.get_component<TilemapComponent>();
        if( mapcomponent != null ){
            // the other is the map
            if (mapcomponent.map.collidesWith(this.getAbsoluteBox(camera.get_component<PositionComponent>()))) {
                return true;
            }
        }

        // nobody is map - do normal collision
        if( this.box.is_intersecting (other.box)){
            return true;
        }
        return false;
    }

}
