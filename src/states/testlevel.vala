using SDL.Video;

public class Testlevel : GameState {

    public Testlevel (TextureManager textureManager, Renderer renderer) {
        base ("data/testmap.tmx", textureManager, renderer);
    }

    public override void add_entities() {
        base.add_entities();

        var e = this.engine.createEntity();
        e.add_component(new PositionComponent(10, 10));
        e.add_component(new RenderComponent("player", "data/yvonne.png", 30, 17));
        e.add_component(new MovementComponent());
        var ani = new AnimationComponent();
        ani.add_animation (new Animation("still", 0, 3, 6));
        ani.add_animation (new Animation("running", 4, 6, 6));
        e.add_component(ani);
        e.add_component(new CollisionComponent(11, 5, 8, 12));
    }

    public override void create_map(Engine.Entity mapentity) {
        var map = mapentity.get_component<TilemapComponent2>();
        foreach (Tiled.Objectgroup objgrp in map.map.objectgroup) {
            if(objgrp.name == "qboxes") {
                stdout.printf("size %d\n", objgrp.objects.size);
                foreach (Tiled.Object o in objgrp.objects) {
                    var e = this.engine.createEntity();
                    e.add_component(new PositionComponent((int)o.x, (int)o.y));
                    e.add_component(new RenderComponent("qbox", "data/qbox.png", 12, 12));
                }
            }
        }
    }

    /*public override void update() {
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
    }*/

    /*private void collide(Engine.Entity e, Gee.Collection<Engine.Entity> all) {
        var c1 = e.get_component<CollisionComponent>();
        if( c1 == null ){
            return;
        }
        foreach( Engine.Entity other in all ){
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
    }*/

}
