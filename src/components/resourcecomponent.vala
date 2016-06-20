public class ResourceComponent : Engine.Component {
    public enum ResourceType {
        FONT
    }
    public ResourceType type;
    public string identifier;
    public string filename;
    public int ptsize;

    public ResourceComponent(string identifier, string filename, int ptsize, ResourceType type) {
        this.type = type;
        this.identifier = identifier;
        this.filename = filename;
        this.ptsize = ptsize;
    }
}
