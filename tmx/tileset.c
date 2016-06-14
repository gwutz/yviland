/* tileset.c generated by valac 0.32.0, the Vala compiler
 * generated from tileset.vala, do not modify */


#include <glib.h>
#include <glib-object.h>
#include <gxml/gxml.h>
#include <stdlib.h>
#include <string.h>


#define TILED_TYPE_TILESET (tiled_tileset_get_type ())
#define TILED_TILESET(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), TILED_TYPE_TILESET, TiledTileset))
#define TILED_TILESET_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), TILED_TYPE_TILESET, TiledTilesetClass))
#define TILED_IS_TILESET(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), TILED_TYPE_TILESET))
#define TILED_IS_TILESET_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), TILED_TYPE_TILESET))
#define TILED_TILESET_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), TILED_TYPE_TILESET, TiledTilesetClass))

typedef struct _TiledTileset TiledTileset;
typedef struct _TiledTilesetClass TiledTilesetClass;
typedef struct _TiledTilesetPrivate TiledTilesetPrivate;

#define TILED_TYPE_IMAGE (tiled_image_get_type ())
#define TILED_IMAGE(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), TILED_TYPE_IMAGE, TiledImage))
#define TILED_IMAGE_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), TILED_TYPE_IMAGE, TiledImageClass))
#define TILED_IS_IMAGE(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), TILED_TYPE_IMAGE))
#define TILED_IS_IMAGE_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), TILED_TYPE_IMAGE))
#define TILED_IMAGE_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), TILED_TYPE_IMAGE, TiledImageClass))

typedef struct _TiledImage TiledImage;
typedef struct _TiledImageClass TiledImageClass;
#define _g_free0(var) (var = (g_free (var), NULL))
#define _g_object_unref0(var) ((var == NULL) ? NULL : (var = (g_object_unref (var), NULL)))

struct _TiledTileset {
	GXmlSerializableObjectModel parent_instance;
	TiledTilesetPrivate * priv;
};

struct _TiledTilesetClass {
	GXmlSerializableObjectModelClass parent_class;
};

struct _TiledTilesetPrivate {
	gchar* _name;
	gint _tilewidth;
	gint _tileheight;
	gint _tilecount;
	gint _columns;
	TiledImage* _image;
};


static gpointer tiled_tileset_parent_class = NULL;

GType tiled_tileset_get_type (void) G_GNUC_CONST;
GType tiled_image_get_type (void) G_GNUC_CONST;
#define TILED_TILESET_GET_PRIVATE(o) (G_TYPE_INSTANCE_GET_PRIVATE ((o), TILED_TYPE_TILESET, TiledTilesetPrivate))
enum  {
	TILED_TILESET_DUMMY_PROPERTY,
	TILED_TILESET_NAME,
	TILED_TILESET_TILEWIDTH,
	TILED_TILESET_TILEHEIGHT,
	TILED_TILESET_TILECOUNT,
	TILED_TILESET_COLUMNS,
	TILED_TILESET_IMAGE
};
static gchar* tiled_tileset_real_node_name (GXmlSerializableObjectModel* base);
static gchar* tiled_tileset_real_to_string (GXmlSerializableObjectModel* base);
const gchar* tiled_tileset_get_name (TiledTileset* self);
gint tiled_tileset_get_tilewidth (TiledTileset* self);
gint tiled_tileset_get_tileheight (TiledTileset* self);
gint tiled_tileset_get_tilecount (TiledTileset* self);
gint tiled_tileset_get_columns (TiledTileset* self);
TiledImage* tiled_tileset_get_image (TiledTileset* self);
TiledTileset* tiled_tileset_new (void);
TiledTileset* tiled_tileset_construct (GType object_type);
void tiled_tileset_set_name (TiledTileset* self, const gchar* value);
void tiled_tileset_set_tilewidth (TiledTileset* self, gint value);
void tiled_tileset_set_tileheight (TiledTileset* self, gint value);
void tiled_tileset_set_tilecount (TiledTileset* self, gint value);
void tiled_tileset_set_columns (TiledTileset* self, gint value);
void tiled_tileset_set_image (TiledTileset* self, TiledImage* value);
static void tiled_tileset_finalize (GObject* obj);
static void _vala_tiled_tileset_get_property (GObject * object, guint property_id, GValue * value, GParamSpec * pspec);
static void _vala_tiled_tileset_set_property (GObject * object, guint property_id, const GValue * value, GParamSpec * pspec);


static gchar* tiled_tileset_real_node_name (GXmlSerializableObjectModel* base) {
	TiledTileset * self;
	gchar* result = NULL;
	gchar* _tmp0_ = NULL;
	self = (TiledTileset*) base;
	_tmp0_ = g_strdup ("Tileset");
	result = _tmp0_;
	return result;
}


static const gchar* string_to_string (const gchar* self) {
	const gchar* result = NULL;
	g_return_val_if_fail (self != NULL, NULL);
	result = self;
	return result;
}


static gchar* tiled_tileset_real_to_string (GXmlSerializableObjectModel* base) {
	TiledTileset * self;
	gchar* result = NULL;
	const gchar* _tmp0_ = NULL;
	const gchar* _tmp1_ = NULL;
	gint _tmp2_ = 0;
	gchar* _tmp3_ = NULL;
	gchar* _tmp4_ = NULL;
	gint _tmp5_ = 0;
	gchar* _tmp6_ = NULL;
	gchar* _tmp7_ = NULL;
	gint _tmp8_ = 0;
	gchar* _tmp9_ = NULL;
	gchar* _tmp10_ = NULL;
	gint _tmp11_ = 0;
	gchar* _tmp12_ = NULL;
	gchar* _tmp13_ = NULL;
	TiledImage* _tmp14_ = NULL;
	gchar* _tmp15_ = NULL;
	gchar* _tmp16_ = NULL;
	gchar* _tmp17_ = NULL;
	gchar* _tmp18_ = NULL;
	self = (TiledTileset*) base;
	_tmp0_ = self->priv->_name;
	_tmp1_ = string_to_string (_tmp0_);
	_tmp2_ = self->priv->_tilewidth;
	_tmp3_ = g_strdup_printf ("%i", _tmp2_);
	_tmp4_ = _tmp3_;
	_tmp5_ = self->priv->_tileheight;
	_tmp6_ = g_strdup_printf ("%i", _tmp5_);
	_tmp7_ = _tmp6_;
	_tmp8_ = self->priv->_tilecount;
	_tmp9_ = g_strdup_printf ("%i", _tmp8_);
	_tmp10_ = _tmp9_;
	_tmp11_ = self->priv->_columns;
	_tmp12_ = g_strdup_printf ("%i", _tmp11_);
	_tmp13_ = _tmp12_;
	_tmp14_ = self->priv->_image;
	_tmp15_ = gxml_serializable_object_model_to_string ((GXmlSerializableObjectModel*) _tmp14_);
	_tmp16_ = _tmp15_;
	_tmp17_ = g_strconcat ("Tileset: ", _tmp1_, " ", _tmp4_, " ", _tmp7_, " ", _tmp10_, " ", _tmp13_, " ", _tmp16_, NULL);
	_tmp18_ = _tmp17_;
	_g_free0 (_tmp16_);
	_g_free0 (_tmp13_);
	_g_free0 (_tmp10_);
	_g_free0 (_tmp7_);
	_g_free0 (_tmp4_);
	result = _tmp18_;
	return result;
}


TiledTileset* tiled_tileset_construct (GType object_type) {
	TiledTileset * self = NULL;
	self = (TiledTileset*) gxml_serializable_object_model_construct (object_type);
	return self;
}


TiledTileset* tiled_tileset_new (void) {
	return tiled_tileset_construct (TILED_TYPE_TILESET);
}


const gchar* tiled_tileset_get_name (TiledTileset* self) {
	const gchar* result;
	const gchar* _tmp0_ = NULL;
	g_return_val_if_fail (self != NULL, NULL);
	_tmp0_ = self->priv->_name;
	result = _tmp0_;
	return result;
}


void tiled_tileset_set_name (TiledTileset* self, const gchar* value) {
	const gchar* _tmp0_ = NULL;
	gchar* _tmp1_ = NULL;
	g_return_if_fail (self != NULL);
	_tmp0_ = value;
	_tmp1_ = g_strdup (_tmp0_);
	_g_free0 (self->priv->_name);
	self->priv->_name = _tmp1_;
	g_object_notify ((GObject *) self, "name");
}


gint tiled_tileset_get_tilewidth (TiledTileset* self) {
	gint result;
	gint _tmp0_ = 0;
	g_return_val_if_fail (self != NULL, 0);
	_tmp0_ = self->priv->_tilewidth;
	result = _tmp0_;
	return result;
}


void tiled_tileset_set_tilewidth (TiledTileset* self, gint value) {
	gint _tmp0_ = 0;
	g_return_if_fail (self != NULL);
	_tmp0_ = value;
	self->priv->_tilewidth = _tmp0_;
	g_object_notify ((GObject *) self, "tilewidth");
}


gint tiled_tileset_get_tileheight (TiledTileset* self) {
	gint result;
	gint _tmp0_ = 0;
	g_return_val_if_fail (self != NULL, 0);
	_tmp0_ = self->priv->_tileheight;
	result = _tmp0_;
	return result;
}


void tiled_tileset_set_tileheight (TiledTileset* self, gint value) {
	gint _tmp0_ = 0;
	g_return_if_fail (self != NULL);
	_tmp0_ = value;
	self->priv->_tileheight = _tmp0_;
	g_object_notify ((GObject *) self, "tileheight");
}


gint tiled_tileset_get_tilecount (TiledTileset* self) {
	gint result;
	gint _tmp0_ = 0;
	g_return_val_if_fail (self != NULL, 0);
	_tmp0_ = self->priv->_tilecount;
	result = _tmp0_;
	return result;
}


void tiled_tileset_set_tilecount (TiledTileset* self, gint value) {
	gint _tmp0_ = 0;
	g_return_if_fail (self != NULL);
	_tmp0_ = value;
	self->priv->_tilecount = _tmp0_;
	g_object_notify ((GObject *) self, "tilecount");
}


gint tiled_tileset_get_columns (TiledTileset* self) {
	gint result;
	gint _tmp0_ = 0;
	g_return_val_if_fail (self != NULL, 0);
	_tmp0_ = self->priv->_columns;
	result = _tmp0_;
	return result;
}


void tiled_tileset_set_columns (TiledTileset* self, gint value) {
	gint _tmp0_ = 0;
	g_return_if_fail (self != NULL);
	_tmp0_ = value;
	self->priv->_columns = _tmp0_;
	g_object_notify ((GObject *) self, "columns");
}


TiledImage* tiled_tileset_get_image (TiledTileset* self) {
	TiledImage* result;
	TiledImage* _tmp0_ = NULL;
	g_return_val_if_fail (self != NULL, NULL);
	_tmp0_ = self->priv->_image;
	result = _tmp0_;
	return result;
}


static gpointer _g_object_ref0 (gpointer self) {
	return self ? g_object_ref (self) : NULL;
}


void tiled_tileset_set_image (TiledTileset* self, TiledImage* value) {
	TiledImage* _tmp0_ = NULL;
	TiledImage* _tmp1_ = NULL;
	g_return_if_fail (self != NULL);
	_tmp0_ = value;
	_tmp1_ = _g_object_ref0 (_tmp0_);
	_g_object_unref0 (self->priv->_image);
	self->priv->_image = _tmp1_;
	g_object_notify ((GObject *) self, "image");
}


static void tiled_tileset_class_init (TiledTilesetClass * klass) {
	tiled_tileset_parent_class = g_type_class_peek_parent (klass);
	g_type_class_add_private (klass, sizeof (TiledTilesetPrivate));
	((GXmlSerializableObjectModelClass *) klass)->node_name = tiled_tileset_real_node_name;
	((GXmlSerializableObjectModelClass *) klass)->to_string = tiled_tileset_real_to_string;
	G_OBJECT_CLASS (klass)->get_property = _vala_tiled_tileset_get_property;
	G_OBJECT_CLASS (klass)->set_property = _vala_tiled_tileset_set_property;
	G_OBJECT_CLASS (klass)->finalize = tiled_tileset_finalize;
	g_object_class_install_property (G_OBJECT_CLASS (klass), TILED_TILESET_NAME, g_param_spec_string ("name", "name", "name", NULL, G_PARAM_STATIC_NAME | G_PARAM_STATIC_NICK | G_PARAM_STATIC_BLURB | G_PARAM_READABLE | G_PARAM_WRITABLE));
	g_object_class_install_property (G_OBJECT_CLASS (klass), TILED_TILESET_TILEWIDTH, g_param_spec_int ("tilewidth", "tilewidth", "tilewidth", G_MININT, G_MAXINT, 0, G_PARAM_STATIC_NAME | G_PARAM_STATIC_NICK | G_PARAM_STATIC_BLURB | G_PARAM_READABLE | G_PARAM_WRITABLE));
	g_object_class_install_property (G_OBJECT_CLASS (klass), TILED_TILESET_TILEHEIGHT, g_param_spec_int ("tileheight", "tileheight", "tileheight", G_MININT, G_MAXINT, 0, G_PARAM_STATIC_NAME | G_PARAM_STATIC_NICK | G_PARAM_STATIC_BLURB | G_PARAM_READABLE | G_PARAM_WRITABLE));
	g_object_class_install_property (G_OBJECT_CLASS (klass), TILED_TILESET_TILECOUNT, g_param_spec_int ("tilecount", "tilecount", "tilecount", G_MININT, G_MAXINT, 0, G_PARAM_STATIC_NAME | G_PARAM_STATIC_NICK | G_PARAM_STATIC_BLURB | G_PARAM_READABLE | G_PARAM_WRITABLE));
	g_object_class_install_property (G_OBJECT_CLASS (klass), TILED_TILESET_COLUMNS, g_param_spec_int ("columns", "columns", "columns", G_MININT, G_MAXINT, 0, G_PARAM_STATIC_NAME | G_PARAM_STATIC_NICK | G_PARAM_STATIC_BLURB | G_PARAM_READABLE | G_PARAM_WRITABLE));
	g_object_class_install_property (G_OBJECT_CLASS (klass), TILED_TILESET_IMAGE, g_param_spec_object ("image", "image", "image", TILED_TYPE_IMAGE, G_PARAM_STATIC_NAME | G_PARAM_STATIC_NICK | G_PARAM_STATIC_BLURB | G_PARAM_READABLE | G_PARAM_WRITABLE));
}


static void tiled_tileset_instance_init (TiledTileset * self) {
	self->priv = TILED_TILESET_GET_PRIVATE (self);
}


static void tiled_tileset_finalize (GObject* obj) {
	TiledTileset * self;
	self = G_TYPE_CHECK_INSTANCE_CAST (obj, TILED_TYPE_TILESET, TiledTileset);
	_g_free0 (self->priv->_name);
	_g_object_unref0 (self->priv->_image);
	G_OBJECT_CLASS (tiled_tileset_parent_class)->finalize (obj);
}


GType tiled_tileset_get_type (void) {
	static volatile gsize tiled_tileset_type_id__volatile = 0;
	if (g_once_init_enter (&tiled_tileset_type_id__volatile)) {
		static const GTypeInfo g_define_type_info = { sizeof (TiledTilesetClass), (GBaseInitFunc) NULL, (GBaseFinalizeFunc) NULL, (GClassInitFunc) tiled_tileset_class_init, (GClassFinalizeFunc) NULL, NULL, sizeof (TiledTileset), 0, (GInstanceInitFunc) tiled_tileset_instance_init, NULL };
		GType tiled_tileset_type_id;
		tiled_tileset_type_id = g_type_register_static (GXML_TYPE_SERIALIZABLE_OBJECT_MODEL, "TiledTileset", &g_define_type_info, 0);
		g_once_init_leave (&tiled_tileset_type_id__volatile, tiled_tileset_type_id);
	}
	return tiled_tileset_type_id__volatile;
}


static void _vala_tiled_tileset_get_property (GObject * object, guint property_id, GValue * value, GParamSpec * pspec) {
	TiledTileset * self;
	self = G_TYPE_CHECK_INSTANCE_CAST (object, TILED_TYPE_TILESET, TiledTileset);
	switch (property_id) {
		case TILED_TILESET_NAME:
		g_value_set_string (value, tiled_tileset_get_name (self));
		break;
		case TILED_TILESET_TILEWIDTH:
		g_value_set_int (value, tiled_tileset_get_tilewidth (self));
		break;
		case TILED_TILESET_TILEHEIGHT:
		g_value_set_int (value, tiled_tileset_get_tileheight (self));
		break;
		case TILED_TILESET_TILECOUNT:
		g_value_set_int (value, tiled_tileset_get_tilecount (self));
		break;
		case TILED_TILESET_COLUMNS:
		g_value_set_int (value, tiled_tileset_get_columns (self));
		break;
		case TILED_TILESET_IMAGE:
		g_value_set_object (value, tiled_tileset_get_image (self));
		break;
		default:
		G_OBJECT_WARN_INVALID_PROPERTY_ID (object, property_id, pspec);
		break;
	}
}


static void _vala_tiled_tileset_set_property (GObject * object, guint property_id, const GValue * value, GParamSpec * pspec) {
	TiledTileset * self;
	self = G_TYPE_CHECK_INSTANCE_CAST (object, TILED_TYPE_TILESET, TiledTileset);
	switch (property_id) {
		case TILED_TILESET_NAME:
		tiled_tileset_set_name (self, g_value_get_string (value));
		break;
		case TILED_TILESET_TILEWIDTH:
		tiled_tileset_set_tilewidth (self, g_value_get_int (value));
		break;
		case TILED_TILESET_TILEHEIGHT:
		tiled_tileset_set_tileheight (self, g_value_get_int (value));
		break;
		case TILED_TILESET_TILECOUNT:
		tiled_tileset_set_tilecount (self, g_value_get_int (value));
		break;
		case TILED_TILESET_COLUMNS:
		tiled_tileset_set_columns (self, g_value_get_int (value));
		break;
		case TILED_TILESET_IMAGE:
		tiled_tileset_set_image (self, g_value_get_object (value));
		break;
		default:
		G_OBJECT_WARN_INVALID_PROPERTY_ID (object, property_id, pspec);
		break;
	}
}



