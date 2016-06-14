namespace Tiled{
    public class Tileset : GXml.SerializableObjectModel {
        public string name { get ; set ; }
        public int tilewidth { get ; set ; }
        public int tileheight { get ; set ; }
        public int tilecount { get ; set ; }
        public int columns { get ; set ; }
        public Image image { get ; set ; }

        public override string node_name() {
            return "Tileset" ;
        }

        public override string to_string() {
            return @"Tileset: $name $tilewidth $tileheight $tilecount $columns $image" ;
        }

    }
}
