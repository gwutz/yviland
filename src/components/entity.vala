public class Entity : GXml.SerializableObjectModel {
    public string name { get; set; }
    [description]
    public GXml.SerializableArrayList<Component> components {
        get;
        set;
        default = new GXml.SerializableArrayList<Component>();
    }

    /*public override bool deserialize_property(GXml.Node property_node) throws GLib.Error {
        Component component = null;
        bool ret = true;
        if( "Component" in property_node.name ){
            var type = Type.from_name (property_node.name);
            if( type == 0 ){
                stdout.printf ("No Component found for %s\n", property_node.name);
                return true;
            }
            Component c = GLib.Object.new(type) as Component;
            foreach( GXml.Node node in property_node.attrs.values ){
                var param = c.get_class ().find_property (node.name);
                Value val = Value (param.value_type);
                string_to_gvalue (node.value, ref val);
                c.set_property (node.name, val);
            }
            foreach( GXml.Node node in property_node.children ){

            }
            component = c;
            ret = false;
        }

        if( component != null ){
            components.add (component);
        }
        // return ret;
        return base.deserialize_property (property_node);
       }*/

    public override bool serialize_use_xml_node_value() {
        return true;
    }

    public override string node_name() {
        return "Entity";
    }

    public override string to_string() {
        return @"Entity: $name";
    }

}
