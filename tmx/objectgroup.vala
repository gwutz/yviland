namespace Tiled{
    public class Objectgroup : GXml.SerializableObjectModel {
        public string name { get ; set ; }
        public GXml.SerializableArrayList<Object> objects { get ; set ; }

        public override string node_name() {
            return "Objectgroup" ;
        }

        public override string to_string() {
            return @"Objectgroup: $name" ;
        }

        public void show() {
            foreach( Object o in objects ){
                stdout.printf (@"$o") ;
            }
        }

    }
}
