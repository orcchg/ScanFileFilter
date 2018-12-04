package com.orcchg.scanfilefilter;

import android.os.Bundle;
import android.support.annotation.Nullable;
import android.support.v7.app.AppCompatActivity;
import android.view.View;
import android.webkit.URLUtil;
import android.widget.Button;
import android.widget.EditText;
import android.widget.ListView;

public class MainActivity extends AppCompatActivity {

    private ListView list;

    @Override
    protected void onCreate(@Nullable Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);

        final EditText etUrl = findViewById(R.id.et_url);
        final EditText etRegexp = findViewById(R.id.et_regexp);
        Button buttonStart = findViewById(R.id.btn_start);
        list = findViewById(R.id.lv_items);

        buttonStart.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                String url = etUrl.getText().toString();
                if (url.isEmpty() || !URLUtil.isValidUrl(url)) {
                    etUrl.setError("Invalid URL!");
                    return;
                }
                String regexp = etRegexp.getText().toString();
                if (regexp.isEmpty()) {  // TODO: check regexp for validity
                    etRegexp.setError("Wrong regexp!");
                    return;
                }

                start(url, regexp);
            }
        });
    }

    private void start(String url, String regexp) {
        //
    }
}
