/* image.c generated by valac 0.32.0, the Vala compiler
 * generated from image.vala, do not modify */


#include <glib.h>
#include <glib-object.h>
#include <gxml/gxml.h>
#include <stdlib.h>
#include <string.h>


#define TILED_TYPE_IMAGE (tiled_image_get_type ())
#define TILED_IMAGE(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), TILED_TYPE_IMAGE, TiledImage))
#define TILED_IMAGE_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), TILED_TYPE_IMAGE, TiledImageClass))
#define TILED_IS_IMAGE(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), TILED_TYPE_IMAGE))
#define TILED_IS_IMAGE_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), TILED_TYPE_IMAGE))
#define TILED_IMAGE_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), TILED_TYPE_IMAGE, TiledImageClass))

typedef struct _TiledImage TiledImage;
typedef struct _TiledImageClass TiledImageClass;
typedef struct _TiledImagePrivate TiledImagePrivate;
#define _g_free0(var) (var = (g_free (var), NULL))

struct _TiledImage {
	GXmlSerializableObjectModel parent_instance;
	TiledImagePrivate * priv;
};

struct _TiledImageClass {
	GXmlSerializableObjectModelClass parent_class;
};

struct _TiledImagePrivate {
	gchar* _source;
	gint _width;
	gint _height;
};


static gpointer tiled_image_parent_class = NULL;

GType tiled_image_get_type (void) G_GNUC_CONST;
#define TILED_IMAGE_GET_PRIVATE(o) (G_TYPE_INSTANCE_GET_PRIVATE ((o), TILED_TYPE_IMAGE, TiledImagePrivate))
enum  {
	TILED_IMAGE_DUMMY_PROPERTY,
	TILED_IMAGE_SOURCE,
	TILED_IMAGE_WIDTH,
	TILED_IMAGE_HEIGHT
};
static gchar* tiled_image_real_node_name (GXmlSerializableObjectModel* base);
static gchar* tiled_image_real_to_string (GXmlSerializableObjectModel* base);
const gchar* tiled_image_get_source (TiledImage* self);
gint tiled_image_get_width (TiledImage* self);
gint tiled_image_get_height (TiledImage* self);
TiledImage* tiled_image_new (void);
TiledImage* tiled_image_construct (GType object_type);
void tiled_image_set_source (TiledImage* self, const gchar* value);
void tiled_image_set_width (TiledImage* self, gint value);
void tiled_image_set_height (TiledImage* self, gint value);
static void tiled_image_finalize (GObject* obj);
static void _vala_tiled_image_get_property (GObject * object, guint property_id, GValue * value, GParamSpec * pspec);
static void _vala_tiled_image_set_property (GObject * object, guint property_id, const GValue * value, GParamSpec * pspec);


static gchar* tiled_image_real_node_name (GXmlSerializableObjectModel* base) {
	TiledImage * self;
	gchar* result = NULL;
	gchar* _tmp0_ = NULL;
	self = (TiledImage*) base;
	_tmp0_ = g_strdup ("Image");
	result = _tmp0_;
	return result;
}


static const gchar* string_to_string (const gchar* self) {
	const gchar* result = NULL;
	g_return_val_if_fail (self != NULL, NULL);
	result = self;
	return result;
}


static gchar* tiled_image_real_to_string (GXmlSerializableObjectModel* base) {
	TiledImage * self;
	gchar* result = NULL;
	const gchar* _tmp0_ = NULL;
	const gchar* _tmp1_ = NULL;
	gint _tmp2_ = 0;
	gchar* _tmp3_ = NULL;
	gchar* _tmp4_ = NULL;
	gint _tmp5_ = 0;
	gchar* _tmp6_ = NULL;
	gchar* _tmp7_ = NULL;
	gchar* _tmp8_ = NULL;
	gchar* _tmp9_ = NULL;
	self = (TiledImage*) base;
	_tmp0_ = self->priv->_source;
	_tmp1_ = string_to_string (_tmp0_);
	_tmp2_ = self->priv->_width;
	_tmp3_ = g_strdup_printf ("%i", _tmp2_);
	_tmp4_ = _tmp3_;
	_tmp5_ = self->priv->_height;
	_tmp6_ = g_strdup_printf ("%i", _tmp5_);
	_tmp7_ = _tmp6_;
	_tmp8_ = g_strconcat ("Image: ", _tmp1_, " ", _tmp4_, " ", _tmp7_, NULL);
	_tmp9_ = _tmp8_;
	_g_free0 (_tmp7_);
	_g_free0 (_tmp4_);
	result = _tmp9_;
	return result;
}


TiledImage* tiled_image_construct (GType object_type) {
	TiledImage * self = NULL;
	self = (TiledImage*) gxml_serializable_object_model_construct (object_type);
	return self;
}


TiledImage* tiled_image_new (void) {
	return tiled_image_construct (TILED_TYPE_IMAGE);
}


const gchar* tiled_image_get_source (TiledImage* self) {
	const gchar* result;
	const gchar* _tmp0_ = NULL;
	g_return_val_if_fail (self != NULL, NULL);
	_tmp0_ = self->priv->_source;
	result = _tmp0_;
	return result;
}


void tiled_image_set_source (TiledImage* self, const gchar* value) {
	const gchar* _tmp0_ = NULL;
	gchar* _tmp1_ = NULL;
	g_return_if_fail (self != NULL);
	_tmp0_ = value;
	_tmp1_ = g_strdup (_tmp0_);
	_g_free0 (self->priv->_source);
	self->priv->_source = _tmp1_;
	g_object_notify ((GObject *) self, "source");
}


gint tiled_image_get_width (TiledImage* self) {
	gint result;
	gint _tmp0_ = 0;
	g_return_val_if_fail (self != NULL, 0);
	_tmp0_ = self->priv->_width;
	result = _tmp0_;
	return result;
}


void tiled_image_set_width (TiledImage* self, gint value) {
	gint _tmp0_ = 0;
	g_return_if_fail (self != NULL);
	_tmp0_ = value;
	self->priv->_width = _tmp0_;
	g_object_notify ((GObject *) self, "width");
}


gint tiled_image_get_height (TiledImage* self) {
	gint result;
	gint _tmp0_ = 0;
	g_return_val_if_fail (self != NULL, 0);
	_tmp0_ = self->priv->_height;
	result = _tmp0_;
	return result;
}


void tiled_image_set_height (TiledImage* self, gint value) {
	gint _tmp0_ = 0;
	g_return_if_fail (self != NULL);
	_tmp0_ = value;
	self->priv->_height = _tmp0_;
	g_object_notify ((GObject *) self, "height");
}


static void tiled_image_class_init (TiledImageClass * klass) {
	tiled_image_parent_class = g_type_class_peek_parent (klass);
	g_type_class_add_private (klass, sizeof (TiledImagePrivate));
	((GXmlSerializableObjectModelClass *) klass)->node_name = tiled_image_real_node_name;
	((GXmlSerializableObjectModelClass *) klass)->to_string = tiled_image_real_to_string;
	G_OBJECT_CLASS (klass)->get_property = _vala_tiled_image_get_property;
	G_OBJECT_CLASS (klass)->set_property = _vala_tiled_image_set_property;
	G_OBJECT_CLASS (klass)->finalize = tiled_image_finalize;
	g_object_class_install_property (G_OBJECT_CLASS (klass), TILED_IMAGE_SOURCE, g_param_spec_string ("source", "source", "source", NULL, G_PARAM_STATIC_NAME | G_PARAM_STATIC_NICK | G_PARAM_STATIC_BLURB | G_PARAM_READABLE | G_PARAM_WRITABLE));
	g_object_class_install_property (G_OBJECT_CLASS (klass), TILED_IMAGE_WIDTH, g_param_spec_int ("width", "width", "width", G_MININT, G_MAXINT, 0, G_PARAM_STATIC_NAME | G_PARAM_STATIC_NICK | G_PARAM_STATIC_BLURB | G_PARAM_READABLE | G_PARAM_WRITABLE));
	g_object_class_install_property (G_OBJECT_CLASS (klass), TILED_IMAGE_HEIGHT, g_param_spec_int ("height", "height", "height", G_MININT, G_MAXINT, 0, G_PARAM_STATIC_NAME | G_PARAM_STATIC_NICK | G_PARAM_STATIC_BLURB | G_PARAM_READABLE | G_PARAM_WRITABLE));
}


static void tiled_image_instance_init (TiledImage * self) {
	self->priv = TILED_IMAGE_GET_PRIVATE (self);
}


static void tiled_image_finalize (GObject* obj) {
	TiledImage * self;
	self = G_TYPE_CHECK_INSTANCE_CAST (obj, TILED_TYPE_IMAGE, TiledImage);
	_g_free0 (self->priv->_source);
	G_OBJECT_CLASS (tiled_image_parent_class)->finalize (obj);
}


GType tiled_image_get_type (void) {
	static volatile gsize tiled_image_type_id__volatile = 0;
	if (g_once_init_enter (&tiled_image_type_id__volatile)) {
		static const GTypeInfo g_define_type_info = { sizeof (TiledImageClass), (GBaseInitFunc) NULL, (GBaseFinalizeFunc) NULL, (GClassInitFunc) tiled_image_class_init, (GClassFinalizeFunc) NULL, NULL, sizeof (TiledImage), 0, (GInstanceInitFunc) tiled_image_instance_init, NULL };
		GType tiled_image_type_id;
		tiled_image_type_id = g_type_register_static (GXML_TYPE_SERIALIZABLE_OBJECT_MODEL, "TiledImage", &g_define_type_info, 0);
		g_once_init_leave (&tiled_image_type_id__volatile, tiled_image_type_id);
	}
	return tiled_image_type_id__volatile;
}


static void _vala_tiled_image_get_property (GObject * object, guint property_id, GValue * value, GParamSpec * pspec) {
	TiledImage * self;
	self = G_TYPE_CHECK_INSTANCE_CAST (object, TILED_TYPE_IMAGE, TiledImage);
	switch (property_id) {
		case TILED_IMAGE_SOURCE:
		g_value_set_string (value, tiled_image_get_source (self));
		break;
		case TILED_IMAGE_WIDTH:
		g_value_set_int (value, tiled_image_get_width (self));
		break;
		case TILED_IMAGE_HEIGHT:
		g_value_set_int (value, tiled_image_get_height (self));
		break;
		default:
		G_OBJECT_WARN_INVALID_PROPERTY_ID (object, property_id, pspec);
		break;
	}
}


static void _vala_tiled_image_set_property (GObject * object, guint property_id, const GValue * value, GParamSpec * pspec) {
	TiledImage * self;
	self = G_TYPE_CHECK_INSTANCE_CAST (object, TILED_TYPE_IMAGE, TiledImage);
	switch (property_id) {
		case TILED_IMAGE_SOURCE:
		tiled_image_set_source (self, g_value_get_string (value));
		break;
		case TILED_IMAGE_WIDTH:
		tiled_image_set_width (self, g_value_get_int (value));
		break;
		case TILED_IMAGE_HEIGHT:
		tiled_image_set_height (self, g_value_get_int (value));
		break;
		default:
		G_OBJECT_WARN_INVALID_PROPERTY_ID (object, property_id, pspec);
		break;
	}
}



