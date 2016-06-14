public class Component : GXml.SerializableObjectModel {
    public override string to_string() {
        return this.get_type ().name ();
    }

}
