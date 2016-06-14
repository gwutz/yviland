namespace Tiled{
    public class Tile : GXml.SerializableObjectModel {
        public int gid { get; set; }

        public override string node_name() {
            return "Tile";
        }

        public override string to_string() {
            return @"Tile: $gid";
        }

    }
}
