package dsl

import com.sun.corba.se.impl.presentation.rmi.DynamicMethodMarshallerImpl
import kotlin.properties.ReadWriteProperty
import kotlin.reflect.KProperty

/**
 * Created by Inno Fang on 2017/11/12.
 */
class MapDelegate(val map: MutableMap<String, String>) : ReadWriteProperty<Any, String> {
    override fun getValue(thisRef: Any, property: KProperty<*>): String {
        return map[property.name] ?: ""
    }

    override fun setValue(thisRef: Any, property: KProperty<*>, value: String) {
        map[property.name] = value
    }

}
