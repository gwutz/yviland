public class RenderComponent : Component {
    public string texture { get; set; default = ""; }

    public override string node_name() {
        return "RenderComponent";
    }

    public override string to_string() {
        return @"RenderComponent: $texture";
    }

}
