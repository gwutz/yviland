using GXml;

namespace Tiled{

    public static Map loadMap(string filename) {
        var map = new Map ();
        try {
            var doc = new GDocument.from_path (filename);
            map.deserialize (doc);
        } catch ( GLib.Error e ){
            GLib.message ("Map loading failed: %s\n", e.message);
        }
        return map;
    }

}
