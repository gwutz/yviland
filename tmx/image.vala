namespace Tiled{
    public class Image : GXml.SerializableObjectModel {
        public string source { get ; set ; }
        public int width { get ; set ; }
        public int height { get ; set ; }

        public override string node_name() {
            return "Image" ;
        }

        public override string to_string() {
            return @"Image: $source $width $height" ;
        }

    }
}
