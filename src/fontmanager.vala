public class FontManager : GLib.Object {
    public HashTable<string, SDLTTF.Font> map;

    public FontManager() {
        map = new HashTable<string, SDLTTF.Font>(str_hash, str_equal);
    }

    public void load(string identifier, string filename, int ptsize) {
        debug("LOAD FONT: %s WITH IDENTIFIER %s AND PTSIZE %d", filename,
                identifier, ptsize);
        SDLTTF.Font f = new SDLTTF.Font(filename, ptsize);
        if(f == null) {
            error(SDL.get_error());
        }
        map.insert(identifier, (owned)f);
    }

    public unowned SDLTTF.Font getFont(string identifier) {
        return map.get(identifier);
    }

    public bool loaded(string identifier) {
        return map.contains(identifier);
    }
}
