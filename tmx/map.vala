namespace Tiled{
    public class Map : GXml.SerializableObjectModel {

        public enum Orientation {
            ORTHOGONAL,
            ISOMETRIC,
            STAGGERED,
            HEXAGONAL
        }

        public string version { get; set; }
        public Orientation orientation { get; set; }
        public string renderorder { get; set; }
        public int width { get; set; }
        public int height { get; set; }
        public int tilewidth { get; set; }
        public int tileheight { get; set; }
        public GXml.SerializableArrayList<Tileset> tileset { get; set; default = new GXml.SerializableArrayList<Tileset>(); }
        public GXml.SerializableArrayList<Layer> layer { get; set; default = new GXml.SerializableArrayList<Layer>(); }
        public GXml.SerializableArrayList<Objectgroup> objectgroup { get; set; default = new GXml.SerializableArrayList<Objectgroup>(); }

        public override bool deserialize_property(GXml.Node property_node) throws GLib.Error {

            if( property_node.name == "orientation" ){
                switch( property_node.value ){
                case "orthogonal":
                    this.orientation = Orientation.ORTHOGONAL;
                    break;
                }
            }

            return base.deserialize_property (property_node);
        }

        public override string node_name() {
            return "Map";
        }

        public override string to_string() {
            return @"Map: $version $orientation $renderorder $width $height $tilewidth $tileheight";
        }

        public bool collidesHorizontal(SDL.Video.Rect box) {
            var bottom = box.y + (int)box.h;
            Tile t = getTileAt(box.x+(int)box.w, bottom);

            if(t.gid < 128 && t.gid > 0) {
                var tilebox = SDL.Video.Rect() {
                    x = (box.x / tilewidth) * tilewidth,
                    y = (box.y / tileheight) * tileheight,
                    w = tilewidth,
                    h = tileheight
                };
                //stdout.printf(getRectAsString(tilebox));
                if(box.is_intersecting(tilebox)) {
                    return true;
                }
            }

            t = getTileAt(box.x, bottom);

            if(t.gid < 128 && t.gid > 0) {
                var tilebox = SDL.Video.Rect() {
                    x = (box.x / tilewidth) * tilewidth,
                    y = (box.y / tileheight) * tileheight,
                    w = tilewidth,
                    h = tileheight
                };
                //stdout.printf(getRectAsString(tilebox));
                if(box.is_intersecting(tilebox)) {
                    return true;
                }
            }

            return false;
        }

        public bool collidesWith(SDL.Video.Rect box) {
            // check bottom left
            var bottom = box.y + (int)box.h;
            Tile t = getTileAt(box.x, bottom);

            if(t.gid < 128 && t.gid > 0) {
                var tilebox = SDL.Video.Rect() {
                    x = (box.x / tilewidth) * tilewidth,
                    y = (box.y / tileheight) * tileheight + 2,
                    w = tilewidth,
                    h = tileheight
                };
                //stdout.printf(getRectAsString(tilebox));
                if(box.is_intersecting(tilebox)) {
                    return true;
                }
            }

            t = getTileAt(box.x+(int)box.w, bottom);

            if(t.gid < 128 && t.gid > 0) {
                var tilebox = SDL.Video.Rect() {
                    x = (box.x / tilewidth) * tilewidth,
                    y = (box.y / tileheight) * tileheight +2,
                    w = tilewidth,
                    h = tileheight
                };

                if(box.is_intersecting(tilebox)) {
                    return true;
                }
            }

            return false;
        }

        public Tile getTileAt(int x, int y) {
            var xnum = x / tilewidth;
            var ynum = y / tileheight;
            //stdout.printf(@"$xnum $ynum $height $width\n");
            var tilenumber = xnum + ynum * width;
            if(tilenumber < layer[0].data.tiles.size) {
                return layer[0].data.tiles[tilenumber];
            }
            var t = new Tile();
            t.gid = 0;
            return t;
        }

        private string getRectAsString(SDL.Video.Rect rect) {
            return "%d, %d, %u, %u\n".printf(rect.x, rect.y, rect.w, rect.h);
        }
    }
}
