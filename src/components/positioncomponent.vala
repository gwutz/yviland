public class PositionComponent : Component {
    public int x { get; set; }
    public int y { get; set; }

    public override string node_name() {
        return "PositionComponent";
    }

    public override string to_string() {
        return @"PositionComponent: $x $y";
    }

}
