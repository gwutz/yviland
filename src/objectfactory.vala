using Gee;
using Json;
using SDL;

public class ObjectFactory : GLib.Object {
    private TextureManager textureManager;
    private unowned SDL.Video.Renderer renderer;
    public ObjectFactory (TextureManager textureManager, SDL.Video.Renderer renderer) {
        this.textureManager = textureManager;
        this.renderer = renderer;
    }

    public Gee.List<Entity> getObjects() {
        Gee.List<Entity> list = new Gee.ArrayList<Entity>();
        var parser = new Parser ();
        try {
            parser.load_from_file ("data/player.json");
            var root = parser.get_root ();
            var obj = root.get_object ();
            unowned Json.Node entities = obj.get_member ("entities");
            foreach( unowned Json.Node item in entities.get_array ().get_elements ()){
                list.add (process_entity (item));
            }
        } catch ( Error e ){
            stdout.printf ("Cant initialize Objects: %s\n", e.message);
        }
        return list;
    }

    private Entity process_entity(Json.Node node) {
        Entity e = new Entity ();
        unowned Json.Object obj = node.get_object ();

        foreach( unowned string name in obj.get_members ()){
            switch( name ){
            case "name":
                e.set_name (obj.get_string_member (name));
                break;
            case "RenderComponent":
                unowned Json.Node render = obj.get_member (name);
                e.add_component (process_render_component (render, e.get_name ()));
                break;
            case "PositionComponent":
                unowned Json.Node pos = obj.get_member (name);
                e.add_component (process_position_component (pos));
                break;
            case "AnimationComponent":
                unowned Json.Node ani = obj.get_member (name);
                e.add_component (process_animation_component (ani));
                break;
            case "MovementComponent":
                // unowned Json.Node mov = obj.get_member (name);
                // e.add_component (process_movement_component (mov));
                e.add_component (new MovementComponent ());
                break;
            }
        }

        stdout.printf ("name: %s\n", e.get_name ());
        return e;
    }

    private RenderComponent process_render_component(Json.Node node, string identifier) {
        unowned Json.Object obj = node.get_object ();
        uint h = 0, w = 0;
        foreach( unowned string name in obj.get_members ()){
            switch( name ){
            case "texture":
                var texture = this.textureManager.load (identifier, obj.get_string_member (name), this.renderer);
                texture.get_texture ().query (null, null, out w, out h);
                break;
            }
        }
        stdout.printf ("width: %u height: %u\n", w, h);
        return new RenderComponent (identifier, w, h);
    }

    private PositionComponent process_position_component(Json.Node node) {
        unowned Json.Object obj = node.get_object ();
        int x = 0;
        int y = 0;
        foreach( unowned string name in obj.get_members ()){
            switch( name ){
            case "x":
                x = (int) obj.get_int_member (name);
                break;
            case "y":
                y = (int) obj.get_int_member (name);
                break;
            }
        }
        return new PositionComponent (x, y);
    }

    private AnimationComponent process_animation_component(Json.Node node) {
        unowned Json.Object obj = node.get_object ();
        AnimationComponent ani = new AnimationComponent ();
        Gee.List<Animation> animations;
        foreach( unowned string name in obj.get_members ()){
            switch( name ){
            case "sprite_width":
                ani.sprite_width = (int) obj.get_int_member (name);
                break;
            case "animations":
                unowned Json.Node n = obj.get_member (name);
                animations = process_animations (n);
                foreach( Animation a in animations ){
                    ani.add_animation (a);
                }
                break;
            }
        }

        return ani;
    }

    private Gee.List<Animation> process_animations(Json.Node node) {
        Gee.List<Animation> animations = new ArrayList<Animation>();
        unowned Json.Array array = node.get_array ();
        foreach( unowned Json.Node item in array.get_elements ()){
            unowned Json.Object inner_obj = item.get_object ();
            string aniname = "";
            int begin = 0;
            int end = 0;
            int frames_between = 1;
            foreach( unowned string name in inner_obj.get_members ()){

                switch( name ){
                case "name":
                    aniname = inner_obj.get_string_member (name);
                    break;
                case "begin":
                    begin = (int) inner_obj.get_int_member (name);
                    break;
                case "end":
                    end = (int) inner_obj.get_int_member (name);
                    break;
                case "frames_between":
                    frames_between = (int) inner_obj.get_int_member (name);
                    break;
                }
            }
            animations.add (new Animation (aniname, begin, end, frames_between));
        }
        return animations;
    }

    private MovementComponent process_movement_component(Json.Node node) {
        return new MovementComponent ();
    }

}
