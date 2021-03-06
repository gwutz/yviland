/* entity.c generated by valac 0.32.0, the Vala compiler
 * generated from entity.vala, do not modify */


#include <glib.h>
#include <glib-object.h>
#include <stdlib.h>
#include <string.h>
#include <gee.h>


#define ENGINE_TYPE_ENTITY (engine_entity_get_type ())
#define ENGINE_ENTITY(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), ENGINE_TYPE_ENTITY, EngineEntity))
#define ENGINE_ENTITY_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), ENGINE_TYPE_ENTITY, EngineEntityClass))
#define ENGINE_IS_ENTITY(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), ENGINE_TYPE_ENTITY))
#define ENGINE_IS_ENTITY_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), ENGINE_TYPE_ENTITY))
#define ENGINE_ENTITY_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), ENGINE_TYPE_ENTITY, EngineEntityClass))

typedef struct _EngineEntity EngineEntity;
typedef struct _EngineEntityClass EngineEntityClass;
typedef struct _EngineEntityPrivate EngineEntityPrivate;

#define ENGINE_TYPE_COMPONENT (engine_component_get_type ())
#define ENGINE_COMPONENT(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), ENGINE_TYPE_COMPONENT, EngineComponent))
#define ENGINE_COMPONENT_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), ENGINE_TYPE_COMPONENT, EngineComponentClass))
#define ENGINE_IS_COMPONENT(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), ENGINE_TYPE_COMPONENT))
#define ENGINE_IS_COMPONENT_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), ENGINE_TYPE_COMPONENT))
#define ENGINE_COMPONENT_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), ENGINE_TYPE_COMPONENT, EngineComponentClass))

typedef struct _EngineComponent EngineComponent;
typedef struct _EngineComponentClass EngineComponentClass;
#define _g_free0(var) (var = (g_free (var), NULL))
#define _g_object_unref0(var) ((var == NULL) ? NULL : (var = (g_object_unref (var), NULL)))

struct _EngineEntity {
	GObject parent_instance;
	EngineEntityPrivate * priv;
};

struct _EngineEntityClass {
	GObjectClass parent_class;
};

struct _EngineEntityPrivate {
	gchar* _name;
	GeeList* components;
};


static gpointer engine_entity_parent_class = NULL;

GType engine_entity_get_type (void) G_GNUC_CONST;
GType engine_component_get_type (void) G_GNUC_CONST;
#define ENGINE_ENTITY_GET_PRIVATE(o) (G_TYPE_INSTANCE_GET_PRIVATE ((o), ENGINE_TYPE_ENTITY, EngineEntityPrivate))
enum  {
	ENGINE_ENTITY_DUMMY_PROPERTY,
	ENGINE_ENTITY_NAME
};
EngineEntity* engine_entity_new (void);
EngineEntity* engine_entity_construct (GType object_type);
EngineEntity* engine_entity_new_with_name (const gchar* name);
EngineEntity* engine_entity_construct_with_name (GType object_type, const gchar* name);
void engine_entity_set_name (EngineEntity* self, const gchar* value);
gpointer engine_entity_get_component (EngineEntity* self, GType t_type, GBoxedCopyFunc t_dup_func, GDestroyNotify t_destroy_func);
gpointer engine_entity_get_components (EngineEntity* self, GType t_type, GBoxedCopyFunc t_dup_func, GDestroyNotify t_destroy_func);
void engine_entity_add_component (EngineEntity* self, EngineComponent* c);
void engine_component_set_entity (EngineComponent* self, EngineEntity* value);
gboolean engine_entity_has_component (EngineEntity* self, GType t);
const gchar* engine_entity_get_name (EngineEntity* self);
static void engine_entity_finalize (GObject* obj);
static void _vala_engine_entity_get_property (GObject * object, guint property_id, GValue * value, GParamSpec * pspec);
static void _vala_engine_entity_set_property (GObject * object, guint property_id, const GValue * value, GParamSpec * pspec);


EngineEntity* engine_entity_construct (GType object_type) {
	EngineEntity * self = NULL;
	GeeArrayList* _tmp0_ = NULL;
	self = (EngineEntity*) g_object_new (object_type, NULL);
	_tmp0_ = gee_array_list_new (ENGINE_TYPE_COMPONENT, (GBoxedCopyFunc) g_object_ref, g_object_unref, NULL, NULL, NULL);
	_g_object_unref0 (self->priv->components);
	self->priv->components = (GeeList*) _tmp0_;
	return self;
}


EngineEntity* engine_entity_new (void) {
	return engine_entity_construct (ENGINE_TYPE_ENTITY);
}


EngineEntity* engine_entity_construct_with_name (GType object_type, const gchar* name) {
	EngineEntity * self = NULL;
	const gchar* _tmp0_ = NULL;
	g_return_val_if_fail (name != NULL, NULL);
	self = (EngineEntity*) engine_entity_construct (object_type);
	_tmp0_ = name;
	engine_entity_set_name (self, _tmp0_);
	return self;
}


EngineEntity* engine_entity_new_with_name (const gchar* name) {
	return engine_entity_construct_with_name (ENGINE_TYPE_ENTITY, name);
}


static gpointer _g_object_ref0 (gpointer self) {
	return self ? g_object_ref (self) : NULL;
}


gpointer engine_entity_get_component (EngineEntity* self, GType t_type, GBoxedCopyFunc t_dup_func, GDestroyNotify t_destroy_func) {
	gpointer result = NULL;
	g_return_val_if_fail (self != NULL, NULL);
	{
		GeeList* _c_list = NULL;
		GeeList* _tmp0_ = NULL;
		GeeList* _tmp1_ = NULL;
		gint _c_size = 0;
		GeeList* _tmp2_ = NULL;
		gint _tmp3_ = 0;
		gint _tmp4_ = 0;
		gint _c_index = 0;
		_tmp0_ = self->priv->components;
		_tmp1_ = _g_object_ref0 (_tmp0_);
		_c_list = _tmp1_;
		_tmp2_ = _c_list;
		_tmp3_ = gee_collection_get_size ((GeeCollection*) _tmp2_);
		_tmp4_ = _tmp3_;
		_c_size = _tmp4_;
		_c_index = -1;
		while (TRUE) {
			gint _tmp5_ = 0;
			gint _tmp6_ = 0;
			gint _tmp7_ = 0;
			EngineComponent* c = NULL;
			GeeList* _tmp8_ = NULL;
			gint _tmp9_ = 0;
			gpointer _tmp10_ = NULL;
			GType t = 0UL;
			EngineComponent* _tmp11_ = NULL;
			GType _tmp12_ = 0UL;
			GType _tmp13_ = 0UL;
			_tmp5_ = _c_index;
			_c_index = _tmp5_ + 1;
			_tmp6_ = _c_index;
			_tmp7_ = _c_size;
			if (!(_tmp6_ < _tmp7_)) {
				break;
			}
			_tmp8_ = _c_list;
			_tmp9_ = _c_index;
			_tmp10_ = gee_list_get (_tmp8_, _tmp9_);
			c = (EngineComponent*) _tmp10_;
			t = t_type;
			_tmp11_ = c;
			_tmp12_ = G_TYPE_FROM_INSTANCE ((GObject*) _tmp11_);
			_tmp13_ = t;
			if (_tmp12_ == _tmp13_) {
				EngineComponent* _tmp14_ = NULL;
				gpointer _tmp15_ = NULL;
				_tmp14_ = c;
				_tmp15_ = ((((gconstpointer) _tmp14_) != NULL) && (t_dup_func != NULL)) ? t_dup_func ((gpointer) ((gconstpointer) _tmp14_)) : ((gpointer) ((gconstpointer) _tmp14_));
				result = _tmp15_;
				_g_object_unref0 (c);
				_g_object_unref0 (_c_list);
				return result;
			}
			_g_object_unref0 (c);
		}
		_g_object_unref0 (_c_list);
	}
	result = NULL;
	return result;
}


gpointer engine_entity_get_components (EngineEntity* self, GType t_type, GBoxedCopyFunc t_dup_func, GDestroyNotify t_destroy_func) {
	gpointer result = NULL;
	g_return_val_if_fail (self != NULL, NULL);
	{
		GeeList* _c_list = NULL;
		GeeList* _tmp0_ = NULL;
		GeeList* _tmp1_ = NULL;
		gint _c_size = 0;
		GeeList* _tmp2_ = NULL;
		gint _tmp3_ = 0;
		gint _tmp4_ = 0;
		gint _c_index = 0;
		_tmp0_ = self->priv->components;
		_tmp1_ = _g_object_ref0 (_tmp0_);
		_c_list = _tmp1_;
		_tmp2_ = _c_list;
		_tmp3_ = gee_collection_get_size ((GeeCollection*) _tmp2_);
		_tmp4_ = _tmp3_;
		_c_size = _tmp4_;
		_c_index = -1;
		while (TRUE) {
			gint _tmp5_ = 0;
			gint _tmp6_ = 0;
			gint _tmp7_ = 0;
			EngineComponent* c = NULL;
			GeeList* _tmp8_ = NULL;
			gint _tmp9_ = 0;
			gpointer _tmp10_ = NULL;
			GType t = 0UL;
			EngineComponent* _tmp11_ = NULL;
			GType _tmp12_ = 0UL;
			GType _tmp13_ = 0UL;
			gboolean _tmp14_ = FALSE;
			_tmp5_ = _c_index;
			_c_index = _tmp5_ + 1;
			_tmp6_ = _c_index;
			_tmp7_ = _c_size;
			if (!(_tmp6_ < _tmp7_)) {
				break;
			}
			_tmp8_ = _c_list;
			_tmp9_ = _c_index;
			_tmp10_ = gee_list_get (_tmp8_, _tmp9_);
			c = (EngineComponent*) _tmp10_;
			t = t_type;
			_tmp11_ = c;
			_tmp12_ = G_TYPE_FROM_INSTANCE ((GObject*) _tmp11_);
			_tmp13_ = t;
			_tmp14_ = g_type_is_a (_tmp12_, _tmp13_);
			if (_tmp14_) {
				EngineComponent* _tmp15_ = NULL;
				gpointer _tmp16_ = NULL;
				_tmp15_ = c;
				_tmp16_ = ((((gconstpointer) _tmp15_) != NULL) && (t_dup_func != NULL)) ? t_dup_func ((gpointer) ((gconstpointer) _tmp15_)) : ((gpointer) ((gconstpointer) _tmp15_));
				result = _tmp16_;
				_g_object_unref0 (c);
				_g_object_unref0 (_c_list);
				return result;
			}
			_g_object_unref0 (c);
		}
		_g_object_unref0 (_c_list);
	}
	result = NULL;
	return result;
}


void engine_entity_add_component (EngineEntity* self, EngineComponent* c) {
	EngineComponent* _tmp0_ = NULL;
	GeeList* _tmp1_ = NULL;
	EngineComponent* _tmp2_ = NULL;
	g_return_if_fail (self != NULL);
	g_return_if_fail (c != NULL);
	_tmp0_ = c;
	engine_component_set_entity (_tmp0_, self);
	_tmp1_ = self->priv->components;
	_tmp2_ = c;
	gee_collection_add ((GeeCollection*) _tmp1_, _tmp2_);
}


gboolean engine_entity_has_component (EngineEntity* self, GType t) {
	gboolean result = FALSE;
	g_return_val_if_fail (self != NULL, FALSE);
	{
		GeeList* _c_list = NULL;
		GeeList* _tmp0_ = NULL;
		GeeList* _tmp1_ = NULL;
		gint _c_size = 0;
		GeeList* _tmp2_ = NULL;
		gint _tmp3_ = 0;
		gint _tmp4_ = 0;
		gint _c_index = 0;
		_tmp0_ = self->priv->components;
		_tmp1_ = _g_object_ref0 (_tmp0_);
		_c_list = _tmp1_;
		_tmp2_ = _c_list;
		_tmp3_ = gee_collection_get_size ((GeeCollection*) _tmp2_);
		_tmp4_ = _tmp3_;
		_c_size = _tmp4_;
		_c_index = -1;
		while (TRUE) {
			gint _tmp5_ = 0;
			gint _tmp6_ = 0;
			gint _tmp7_ = 0;
			EngineComponent* c = NULL;
			GeeList* _tmp8_ = NULL;
			gint _tmp9_ = 0;
			gpointer _tmp10_ = NULL;
			EngineComponent* _tmp11_ = NULL;
			GType _tmp12_ = 0UL;
			GType _tmp13_ = 0UL;
			_tmp5_ = _c_index;
			_c_index = _tmp5_ + 1;
			_tmp6_ = _c_index;
			_tmp7_ = _c_size;
			if (!(_tmp6_ < _tmp7_)) {
				break;
			}
			_tmp8_ = _c_list;
			_tmp9_ = _c_index;
			_tmp10_ = gee_list_get (_tmp8_, _tmp9_);
			c = (EngineComponent*) _tmp10_;
			_tmp11_ = c;
			_tmp12_ = G_TYPE_FROM_INSTANCE ((GObject*) _tmp11_);
			_tmp13_ = t;
			if (_tmp12_ == _tmp13_) {
				result = TRUE;
				_g_object_unref0 (c);
				_g_object_unref0 (_c_list);
				return result;
			}
			_g_object_unref0 (c);
		}
		_g_object_unref0 (_c_list);
	}
	result = FALSE;
	return result;
}


const gchar* engine_entity_get_name (EngineEntity* self) {
	const gchar* result;
	const gchar* _tmp0_ = NULL;
	g_return_val_if_fail (self != NULL, NULL);
	_tmp0_ = self->priv->_name;
	result = _tmp0_;
	return result;
}


void engine_entity_set_name (EngineEntity* self, const gchar* value) {
	const gchar* _tmp0_ = NULL;
	gchar* _tmp1_ = NULL;
	g_return_if_fail (self != NULL);
	_tmp0_ = value;
	_tmp1_ = g_strdup (_tmp0_);
	_g_free0 (self->priv->_name);
	self->priv->_name = _tmp1_;
	g_object_notify ((GObject *) self, "name");
}


static void engine_entity_class_init (EngineEntityClass * klass) {
	engine_entity_parent_class = g_type_class_peek_parent (klass);
	g_type_class_add_private (klass, sizeof (EngineEntityPrivate));
	G_OBJECT_CLASS (klass)->get_property = _vala_engine_entity_get_property;
	G_OBJECT_CLASS (klass)->set_property = _vala_engine_entity_set_property;
	G_OBJECT_CLASS (klass)->finalize = engine_entity_finalize;
	g_object_class_install_property (G_OBJECT_CLASS (klass), ENGINE_ENTITY_NAME, g_param_spec_string ("name", "name", "name", NULL, G_PARAM_STATIC_NAME | G_PARAM_STATIC_NICK | G_PARAM_STATIC_BLURB | G_PARAM_READABLE | G_PARAM_WRITABLE));
}


static void engine_entity_instance_init (EngineEntity * self) {
	self->priv = ENGINE_ENTITY_GET_PRIVATE (self);
}


static void engine_entity_finalize (GObject* obj) {
	EngineEntity * self;
	self = G_TYPE_CHECK_INSTANCE_CAST (obj, ENGINE_TYPE_ENTITY, EngineEntity);
	_g_free0 (self->priv->_name);
	_g_object_unref0 (self->priv->components);
	G_OBJECT_CLASS (engine_entity_parent_class)->finalize (obj);
}


GType engine_entity_get_type (void) {
	static volatile gsize engine_entity_type_id__volatile = 0;
	if (g_once_init_enter (&engine_entity_type_id__volatile)) {
		static const GTypeInfo g_define_type_info = { sizeof (EngineEntityClass), (GBaseInitFunc) NULL, (GBaseFinalizeFunc) NULL, (GClassInitFunc) engine_entity_class_init, (GClassFinalizeFunc) NULL, NULL, sizeof (EngineEntity), 0, (GInstanceInitFunc) engine_entity_instance_init, NULL };
		GType engine_entity_type_id;
		engine_entity_type_id = g_type_register_static (G_TYPE_OBJECT, "EngineEntity", &g_define_type_info, 0);
		g_once_init_leave (&engine_entity_type_id__volatile, engine_entity_type_id);
	}
	return engine_entity_type_id__volatile;
}


static void _vala_engine_entity_get_property (GObject * object, guint property_id, GValue * value, GParamSpec * pspec) {
	EngineEntity * self;
	self = G_TYPE_CHECK_INSTANCE_CAST (object, ENGINE_TYPE_ENTITY, EngineEntity);
	switch (property_id) {
		case ENGINE_ENTITY_NAME:
		g_value_set_string (value, engine_entity_get_name (self));
		break;
		default:
		G_OBJECT_WARN_INVALID_PROPERTY_ID (object, property_id, pspec);
		break;
	}
}


static void _vala_engine_entity_set_property (GObject * object, guint property_id, const GValue * value, GParamSpec * pspec) {
	EngineEntity * self;
	self = G_TYPE_CHECK_INSTANCE_CAST (object, ENGINE_TYPE_ENTITY, EngineEntity);
	switch (property_id) {
		case ENGINE_ENTITY_NAME:
		engine_entity_set_name (self, g_value_get_string (value));
		break;
		default:
		G_OBJECT_WARN_INVALID_PROPERTY_ID (object, property_id, pspec);
		break;
	}
}



