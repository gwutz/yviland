namespace Tiled{
    public class Object : GXml.SerializableObjectModel {
        public int id { get ; set ; }
        public string name { get ; set ; }
        public double x { get ; set ; }
        public double y { get ; set ; }
        public double width { get ; set ; }
        public double height { get ; set ; }

        public override string node_name() {
            return "Object" ;
        }

        public override string to_string() {
            return @"Object: $id $name $x $y $width $height" ;
        }

    }
}
