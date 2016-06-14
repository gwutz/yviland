public class Entities : GXml.SerializableObjectModel {
    public GXml.SerializableArrayList<Entity> entities {
        get; set; default = new GXml.SerializableArrayList<Entity>();
    }

    public override string node_name() {
        return "Entities";
    }

    public override string to_string() {
        return @"Entities: ";
    }

    public static int main(string[] argv) {
        // register types

        typeof (RenderComponent).name ();
        typeof (PositionComponent).name ();
        typeof (AnimationComponent).name ();

        var e = new Entities ();
        var doc = new GXml.GDocument.from_path ("../../data/player.xml");
        e.deserialize (doc);

        foreach( Component c in e.entities[0].components ){
            stdout.printf (@"$c\n");
        }
        return 0;
    }

}
