package com.example.blog.utils;

import com.example.blog.domain.Tag;
import com.fasterxml.jackson.core.JsonGenerator;
import com.fasterxml.jackson.databind.JsonSerializer;
import com.fasterxml.jackson.databind.SerializerProvider;

import java.io.IOException;
import java.util.Set;

/**
 * Created by Inno Fang on 2018/4/25.
 */
public class TagSerialize extends JsonSerializer<Tag> {

    @Override
    public void serialize(Tag value, JsonGenerator gen, SerializerProvider serializers) throws IOException {
            gen.writeString(value.getName());
    }
}
