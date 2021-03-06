using SDL.Video;

public class CollisionComponent : Engine.Component {
    public Rect box { get; set; }
    public collisionFunc collision;

    public delegate void collisionFunc();

    public CollisionComponent (int x, int y, uint w, uint h) {
        this.box = Rect () {
            x = x, y = y, w = w, h = h
        };
    }

    public Rect getAbsoluteBox() {
        var pos = this.entity.get_component<PositionComponent>();

        return Rect() {
            x = pos.x + pos.velocity_x + box.x,
            y = pos.y + pos.velocity_y + box.y,
            w = box.w,
            h = box.h
        };
    }

    public Rect getHAbsoluteBox() {
        var pos = this.entity.get_component<PositionComponent>();

        return Rect() {
            x = pos.x + pos.velocity_x + box.x,
            y = pos.y + box.y,
            w = box.w,
            h = box.h
        };
    }

    /*public bool collidesWith(CollisionComponent other, Engine.Entity camera) {
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
    }*/

}
