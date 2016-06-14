namespace Tiled{
    public class Data : GXml.SerializableObjectModel {
        public GXml.SerializableArrayList<Tile> tiles { get; set; default = new GXml.SerializableArrayList<Tile>(); }

        public override string node_name() {
            return "Data";
        }

        public override string to_string() {
            return @"Data: ";
        }

    }
}
