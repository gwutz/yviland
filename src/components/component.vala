public abstract class Component : GLib.Object {
    public weak Entity entity { get; set; }
}

public abstract class UpdateComponent : Component {
    public abstract void update();
}
