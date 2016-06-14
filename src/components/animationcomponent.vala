using Gee;

public class AnimationComponent : Engine.Component {
    public string current_animation;
    public int sprite_width;
    private Gee.Map<string, Animation> animations;

    public AnimationComponent () {
        this.animations = new Gee.HashMap<string, Animation>();
    }

    public AnimationComponent.with_width (int sprite_width) {
        this();
        this.sprite_width = sprite_width;
    }

    public void add_animation(Animation a) {
        if( current_animation == null ){
            current_animation = a.get_name ();
        }
        this.animations.set (a.get_name (), a);
    }

    public int get_animation_sprite() {
        var ret = animations.get (current_animation).play_animation ();
        // stdout.printf("sprite nr %d\n", ret);
        return ret;
    }

}

public class Animation : GLib.Object {
    private string name;
    private int begin;
    private int end;
    private int frames_between;
    private int current_frame;
    private int current_sprite;

    public Animation (string name, int begin, int end, int frames_between) {
        this.name = name;
        this.begin = begin;
        this.end = end;
        this.frames_between = frames_between;
        this.current_frame = 0;
        this.current_sprite = begin;
    }

    public int play_animation() {
        if( current_frame >= frames_between ){
            current_frame = 0;
            if( current_sprite >= end ){
                current_sprite = begin;
            } else {
                current_sprite += 1;
            }
        } else {
            current_frame += 1;
        }
        return current_sprite;
    }

    public string get_name() {
        return this.name;
    }

}
