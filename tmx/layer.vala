namespace Tiled{
    public class Layer : GXml.SerializableObjectModel {
        public string name { get ; set ; }
        public int width { get ; set ; }
        public int height { get ; set ; }
        public Data data { get ; set ; }

        public override string node_name() {
            return "Layer" ;
        }

        public override string to_string() {
            return @"Layer: $name $width $height" ;
        }

    }
}
