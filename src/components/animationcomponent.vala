public class AnimationComponent : Component {
    public int sprite_width { get; set; }
    public GXml.SerializableArrayList<Animation> animation {
        get; set; default = new GXml.SerializableArrayList<Animation>();
    }

    public override string node_name() {
        return "AnimationComponent";
    }

    public override string to_string() {
        var str = "AnimationComponent: ";
        str += @"sprite_width: $sprite_width";
        foreach( Animation a in animation ){
            str += @"\n$a";
        }
        return str;
    }

}

public class Animation : GXml.SerializableObjectModel {
    public string name { get; set; }
    public int begin { get; set; }
    public int end { get; set; }
    public int frames_between { get; set; }
    private int current_frame;
    private int current_sprite;

    /*public Animation (string name, int begin, int end, int frames_between) {
        this.name = name;
        this.begin = begin;
        this.end = end;
        this.frames_between = frames_between;
        this.current_frame = 0;
        this.current_sprite = begin;
       }*/

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

    public override string node_name() {
        return "Animation";
    }

    public override string to_string() {
        return @"Animation: $name $begin $end $frames_between";
    }

}
