namespace Tiled{
    public class Object : GXml.SerializableObjectModel {
        public int id { get ; set ; }
        public string name { get ; set ; }
        public double x { get ; set ; }
        public double y { get ; set ; }
        public double width { get ; set ; }
        public double height { get ; set ; }
        public Properties properties { get; set; default = new Properties();}

        public override string node_name() {
            return "object" ;
        }

        public override string to_string() {
            return @"Object: $id $name $x $y $width $height" ;
        }

    }

    public class Properties : GXml.SerializableObjectModel {
        public GXml.SerializableArrayList<Property> properties {
            get;
            set;
            default = new GXml.SerializableArrayList<Property>();
        }

        public override string node_name() {
            return "Properties";
        }

        public override string to_string() {
            return @"Properties: ";
        }
    }

    public class Property : GXml.SerializableObjectModel {
        public string name {get; set;}
        public string value {get; set;}
        public override string node_name() {
            return "property";
        }
        public override string to_string() {
            return @"Property: $name $value";
        }
    }
}
