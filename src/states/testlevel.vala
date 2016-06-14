using SDL.Video;

public class Testlevel : GameState {

    public Testlevel (TextureManager textureManager, Renderer renderer) {
        base ("data/testmap.tmx", textureManager, renderer);

        // player Entity
        var player = new Entity ("player");
        player.add_component (new PositionComponent (10, 10));
        player.add_component (new RenderComponent.withTexture ("player", "data/yvonne.png", textureManager, renderer));
        player.add_component (new MovementComponent ());
        var ani = new AnimationComponent.with_width (30);
        ani.add_animation (new Animation ("still", 0, 3, 6));
        ani.add_animation (new Animation ("running", 4, 6, 6));
        player.add_component (ani);
        var tmp = new CollisionComponent (11, 5, 8, 12);
        tmp.collision = () => {
            var pos = player.get_component<PositionComponent>();
            pos.reset_position();
        };
        player.add_component (tmp);
        player.add_component(new GravityComponent());

        objects.set (player.name, player);
    }

    public override void update() {
        base.update();
        Entity camera = objects.get("camera");

        foreach( Entity e in this.objects.values ){
            if (e == camera) continue;
            var component = e.get_component<MovementComponent>();
            if( component != null ){
                var pos = e.get_component<PositionComponent>();

                var cameracomp = camera.get_component<CameraComponent>();
                var camerapos = camera.get_component<PositionComponent>();
                //stdout.printf ("%d - camera.x %d camera.w %u\n", pos.next_x, this.camera.x, camera.w);
                if( pos.next_x + 15 > (int) cameracomp.w / 2 ){
                    pos.next_x = pos.x;
                    camerapos.x = camerapos.x + 1;
                } else if( pos.next_x + 16 < (int) cameracomp.w / 2 ){
                    if( camerapos.x <= 0 ){

                    } else {
                        pos.next_x = pos.x;
                        camerapos.x = camerapos.x - 1;
                    }
                }
            }
            collide (e, this.objects.values);
        }
    }

    private void collide(Entity e, Gee.Collection<Entity> all) {
        var c1 = e.get_component<CollisionComponent>();
        if( c1 == null ){
            return;
        }
        foreach( Entity other in all ){
            if( other.name != e.name ){
                var c2 = other.get_component<CollisionComponent>();
                if( c2 != null ){
                    if( c1.collidesWith (c2, objects.get("camera"))) {
                        if(c1.collision != null)
                            c1.collision ();
                    }
                }
            }
        }
    }

}
