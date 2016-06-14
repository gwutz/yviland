using Gee;

public class Entity : GLib.Object {
    public string name { get; set; }
    private Gee.List<Component> components;

    public Entity (string name) {
        this.name = name;
        components = new ArrayList<Component>();
    }

    public T ? get_component<T>() {
        foreach( Component c in this.components ){
            Type t = typeof (T);
            if( c.get_type () == t ){
                return (T) c;
            }
        }
        return null;
    }

    public T? get_components<T>() {
        foreach( Component c in this.components ){
            Type t = typeof (T);
            if( c.get_type().is_a(t) ){
                return (T) c;
            }
        }
        return null;
    }

    public void add_component(Component c) {
        c.entity = this;
        components.add (c);

    }

}
