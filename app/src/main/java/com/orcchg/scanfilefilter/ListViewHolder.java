package com.orcchg.scanfilefilter;

import android.support.v7.widget.RecyclerView;
import android.view.View;
import android.widget.TextView;

class ListViewHolder extends RecyclerView.ViewHolder {

    private TextView item;

    ListViewHolder(View view) {
        super(view);
        item = view.findViewById(R.id.tv_item);
    }

    void bind(String text) {
        item.setText(text);
    }
}
